//RCC
#define RCC_AHB1ENR *((int *)0x40023830)
#define RCC_APB2ENR *((int *)0x40023844)
//GPIOB&C
#define GPIOC_MODER *((int *)0x40020800)
#define GPIOB_MODER *(int*)0x40020400
#define GPIOB_ODR *(int*)0x40020414
//ADC
#define ADC_CR1 *((int *)0x40012004)
#define ADC_CR2 *((int *)0x40012008)
#define ADC_SMPR1 *((int *)0x4001200C)
#define ADC_SQR3 *((int *)0x40012034)
#define  ADC_SR *((int *)0x40012000)
#define  ADC_DR *((int *)0x4001204C)
//STK
#define STK_CTRL *((int *)0xE000E010)
#define STK_LOAD *((int *)0xE000E014)
#define STK_VAL *((int *)0xE000E018)
//NVIC
#define NVIC_ISERO *((int *)0xE000E100)

unsigned char temp=0x41;
void inphaselcd(void);
void conphaselcd(void);
void KM_LCD_INIT(void);
void KM_LCD_WRITE_str(char *);
void WRITE_High_Nibble(unsigned char temp);
void WRITE_Low_Nibble(unsigned char temp);
void KM_LCD_WRITE_Cmd(unsigned char temp);
int Pot_value,Temp;
//char str[12]="Temperature:";

void inphase(void)
{
RCC_AHB1ENR |= 0x4; 											//set port  c
while(!(RCC_AHB1ENR & 0x4)); 							//checking wheather port c set or not
RCC_APB2ENR |=(0x01<<8);									//enable adc clock
while(!(RCC_APB2ENR & 0x01<<8));					//wait until adc clock enable
}	
void stk_init()
{
	STK_CTRL=0x05;
	STK_VAL=0x123;
}
void km_delayms(int x)
{
	STK_LOAD=x*16000;
	while((STK_CTRL&0x1<<16)==0);
}
void conphase()
{
	GPIOC_MODER&=~(0xfffffffC);												//port c frist bit"pb0"
	GPIOC_MODER|=(0x00000003);												//load 1st"11" bit tok analog to "pb0"
	
}
void KM_ADC_INIT()
{
	ADC_SMPR1=0x7;													//480 clock cycles
	ADC_SQR3&=0x1f;													//clear (4:0) regular sequence register
	ADC_SQR3|=0x0a;													//load 01010 in (4:0) bit position to set adc1_11 as 1st convernsion
	ADC_CR1&=~(0x3<<24);										//12th-bit(adcclk cycles)	
																						/*Resolution. The ADC resolution is defined 
																						as the smallest incremental voltage that can be
																						recognized and thus causes achange in the digital output. 
																						It is expressed as the number of bits output by the ADC. 
																						Therefore, an ADC which converts the analog signal to a 12-bit digital
																						value has a resolution of 12 bits.*/
	ADC_CR1|=(0x01<<5);											//12th-bit(adcclk cycles)	
	ADC_CR2|=0x0400;												//set 10th bit (EOCS)end of conversion selection
	ADC_CR2|=0x01;													//set 0th bit (ADON)to turn on adc1
	NVIC_ISERO |=(0x01<<18);								//18TH PIN IN NVIC
}

void WRITE_High_Nibble(unsigned char temp)
	{
		
		GPIOB_ODR &=~(0x0f);					//clear lower nibble of gpoib_odr
		GPIOB_ODR |=temp>>4;					//higher nibble position changed to lower nibble
		GPIOB_ODR |=(0x01<<8);				//enable pb-8 pin
		km_delayms(10);								//delay 10ms
		GPIOB_ODR &=~(0x01<<8);				//clear pb-8 pin
		
	}
	void WRITE_Low_Nibble(unsigned char temp)
	{
		GPIOB_ODR &=~(0x0f);
		
		temp=temp<<4;
		temp=temp>>4;
		GPIOB_ODR |=temp;
		GPIOB_ODR |=(0x01<<8);
		km_delayms(10);
		GPIOB_ODR &=~(0x01<<8);
		
	}
void KM_LCD_WRITE_DATA(unsigned char temp)
{
	GPIOB_ODR|=0x1<<4;   									 //RS=1 means data register
	WRITE_High_Nibble(temp);
  WRITE_Low_Nibble(temp);
}	

void KM_LCD_INIT(void)
 {
	km_delayms(20);													//  20ms delay
	KM_LCD_WRITE_Cmd(0x33);		
	km_delayms(1);
	KM_LCD_WRITE_Cmd(0x32);
	KM_LCD_WRITE_Cmd(0x0C);									//DISPLAY ON CURSER OFF
	KM_LCD_WRITE_Cmd(0x01);									//CLEAR SCREEN
	 
																					//KM_LCD_WRITE_Cmd(0xC0);//seacond line
}

void ADC_IRQHandler(void)
{
	Pot_value=ADC_DR;												//collect data from data register
	Temp=Pot_value/10;											//collect data from pot_value
  KM_LCD_WRITE_DATA((Temp/10)+48);
  KM_LCD_WRITE_DATA((Temp%10)+48);
	ADC_CR2|=0x1<<30;												// swstart :start configuration register channel
	ADC_CR2 &=~(0x1<<30);										//clear trigger
	KM_LCD_WRITE_Cmd(0x10);
	KM_LCD_WRITE_Cmd(0x10);
	km_delayms(500);												//500ms
}

void KM_LCD_WRITE_Cmd(unsigned char temp)
{		
   GPIOB_ODR&=~(0X1<<4);				//RS=0 means command register
		WRITE_High_Nibble(temp);
	  WRITE_Low_Nibble(temp);
	}

 void conphaselcd(void)
 {
GPIOB_MODER&=0xfffcf000;									//clear 0-11 ,16,17,bits in GPIOB_MODER
GPIOB_MODER|=0x00010555;									//load "0,1,0-11,16,17,"bit positions in GPIOB_MODER set to ODR
 }
 void inphaselcd(void)
{
RCC_AHB1ENR |= 0x2; 											//set port  c
while(!(RCC_AHB1ENR & 0x2)); 							//checking wheather port c set or not
}

void KM_LCD_WRITE_str(char  *str)
{
	int i;
	for(i=0;str[i];i++)
	{
		KM_LCD_WRITE_DATA(str[i]);
	}
}
int main()
{
	char str[]="Temperature = ";
	inphase();															//inisilasition port c clk
	conphase();															//set port c to analog mode
	inphaselcd();
	conphaselcd();
	stk_init();								//inisitlation stk clk
	KM_LCD_INIT();
	KM_LCD_WRITE_str(str);
	KM_ADC_INIT();													// km_adc_initasilation     
	
	while(1)
	{
		ADC_CR2|=0x1<<30;											//  SWSTART:start configuration register channel
	}
	
	
}

