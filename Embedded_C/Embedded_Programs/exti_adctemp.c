	//GPIO Physical Addresses
#define RCC_AHB1ENR *((int *)0x40023830)
#define RCC_APB2ENR *((int *)0x40023844)
#define GPIOC_MODER *((int *)0x40020800)
	//SysTick Physical Addresses
#define STK_CTRL *((int *)0xE000E010)
#define STK_LOAD *((int *)0xE000E014)
#define STK_VAL *((int *)0xE000E018)
	//ADC Physical Addresses
#define ADC_SMPR1 *((int *)0x4001200c)
#define ADC_SQR3 *((int *)0x40012034)
#define ADC_CR1 *((int *)0x40012004)
#define ADC_CR2 *((int *)0x40012008)
#define ADC_SR *((int *)0x40012000)
#define ADC_DR *((int *)0x4001204c)
	//Physical addresses for LCD
#define RCC_AHB1ENR *((int *)0x40023830)
#define GPIOB_MODER *((int *)0x40020400) 
#define GPIOB_ODR *((int *)0x40020414)
	//NVIC POSITION
#define NVIC_ISER0 *((int *)0xE000E100)
	
	//LCD Functions
void LCD_Common(void);
void KM_LCD_Write_Cmd( unsigned char );
void KM_LCD_Write_Data( unsigned char );
void KM_LCD_Init(void);
void KM_LCD_Write_Data( unsigned char );
void KM_LCD_Write_Str(char *);
void KM_delayms(int x);
void write_high_nibble( unsigned char );
void write_low_nibble( unsigned char );
void PORTB_initial(void);
void PORTB_config(void);
void MY_DISPLAY(unsigned int );

//PA
//#define RCC_AHB1ENR *((int *)0x40023830)
//#define GPIOB_MODER *((int *)0x40020400) 
//#define GPIOB_ODR *((int *)0x40020414)
#include "HEAD.h"

void PORTB_initial(void)
{
	//PORTB initialization.
RCC_AHB1ENR |= 0x2;				//reading RCC_AHB1ENR register and setting 1st bit without disturbing others.
while(!(RCC_AHB1ENR & 0x2));  //wait untill 1st bit value 1 or clock is set.
}

//PORTB Configuration.
void PORTB_config(void)
{
GPIOB_MODER &= 0xfffcf000;
GPIOB_MODER |= 0x00010555;	//PORTB configuration for PB0,PB1,PB2,PB3,PB4,PB5,PB8 set to Output mode.
GPIOB_ODR &= 0xfffffeff;	//PB8 clear (EN=0)
GPIOB_ODR &= 0xffffffef;	//PB4 cleared (RS=0) or enabling command register.
GPIOB_ODR &= 0xffffffdf;	//PB5 cleared (RW=0)
}


//high nibble function.
void write_high_nibble( unsigned char temp)
{
	GPIOB_ODR &= 0xfffffff0;	//clear first 4 bits of GPIOB_ODR.
	GPIOB_ODR |= (temp>>4);
	GPIOB_ODR |= 0x00000100;	//PB8 set (EN=1);
	KM_delayms(10);
	GPIOB_ODR &= 0xfffffeff;	//PB8 clear (EN=0)
	
}


void write_low_nibble( unsigned char temp)
{
	GPIOB_ODR &= 0xfffffff0;	//clear first 4 bits of GPIOB_ODR.
	
	GPIOB_ODR |= (temp&0x0f);	//also write like this for lower 
		
	//GPIOB_ODR |= ((temp<<4)>>4); //even logic is correct not getting correct result
	GPIOB_ODR |= 0x00000100;	//PB8 set (EN=1);
	KM_delayms(10);
	GPIOB_ODR &= 0xfffffeff;	//PB8 clear (EN=0)
}


void KM_LCD_Write_Cmd( unsigned char temp)
{
	GPIOB_ODR &= 0xffffffef;	//PB4 cleared (RS=0) or enabling command register.
	write_high_nibble(temp);
	write_low_nibble(temp);
	
}


void KM_LCD_Write_Data( unsigned char t)
{
	GPIOB_ODR |= 0x00000010;	//PB4 set (RS=1) or enabling data register.
	
	write_high_nibble(t);
	
	write_low_nibble(t);
		
	GPIOB_ODR &= 0xffffffef;	//PB4 cleared (RS=0) or enabling command register.
}
void KM_LCD_Write_Str(char *st)
{
int i=0;
for(i=0;st[i];i++)
KM_LCD_Write_Data(st[i]);
}

//LCD Initialization.
void KM_LCD_Init(void)
{
	KM_delayms(20);
	KM_LCD_Write_Cmd(0x33);
	KM_delayms(1);
	KM_LCD_Write_Cmd (0x32);
	KM_LCD_Write_Cmd (0x0C);
	KM_LCD_Write_Cmd (0x01);
}
                                                                             
void LCD_Common()
{
	PORTB_initial();
	PORTB_config();
	KM_LCD_Init();
	
}


#include "HEAD.h"	//user define library  for all physical addresses and function declarations.

unsigned int TEMP_Value;	//global variable.
char str[20]="Temperature"; //String to display at begining.

void GPIOC_Init()
{
RCC_AHB1ENR |= 0x4;				//reading RCC_AHB1ENR register and setting bit-2 without disturbing others.
while(!(RCC_AHB1ENR & 0x4));  //wait untill 2nd bit value 1 or clock is set.
}

	//STK initialization
void STK_Init()
{
STK_CTRL = 0x05;	//enabling SystickTimer and Clocksource.
STK_VAL = 0x123;	//clearing STK_VAL register and COUNT FLAG (16th bit in STR_CTRL).
}

void GPIOC_Config()
{
GPIOC_MODER |= 0x00000003;	//set bits 1&0 in GPIOC_MODER (enable PC0 in Analog direction).
}

//Delay Function in ms.
void KM_delayms(int x)
{
STK_LOAD = x*16000;
while((STK_CTRL & (0X1<<16)) == 0);
} 


void KM_ADC_Init(void)
{
	RCC_APB2ENR |= (0x1<<8);	//enabling ADC clock.
	while(!(RCC_APB2ENR & 0x1<<8));	//wait untill ADC clock enable.
	ADC_SMPR1 |= 0x07;	//Smapling SMP10 highest cycles. (for Temp.Sensor)
	
	//ADC_SMPR1 = 0x38;	//Smapling SMP11 highest cycles.	(for Potentiometer)
	
	ADC_SQR3 |= 0x0a;	//load '1010' in 0-4 positions to set ADC_10 as 1st conversion.
	ADC_CR1 &= ~(0x3<<24);	//load '00'in 24-25 positions to set 12th bit resolution.
	ADC_CR2 |= 0x1<<10;	//set 10th bit (EOC selection).
	ADC_CR2 |= 0x1;	//set 0th bit (ADON to turn ON ADC)
	ADC_CR2 |= 0x20;	//set 5th bit( EOCIE) i.e enabling EOCIE interrupt.
	NVIC_ISER0 |= (0x1<<18);	//enabling NVIC_ISER0 18th bit (Enabling ADC Interrupt in NVIC).
}

void KM_ADC_Read(void)
{
	
	ADC_CR2 |= (0x1<<30);	//Start Conversion (SWSTRT enabling).
	
}	

void MY_DISPLAY(unsigned int x)
{
	int i;
	x/= 10;	//Temperature in C = Vout/10ma
	KM_delayms(1);
	KM_LCD_Write_Data((x/10)+48);	//converting first digit in TEMP_Value to character
	KM_LCD_Write_Data((x%10)+48);	//converting second digit in TEMP_Value to character
	KM_LCD_Write_Data('C');	//printing character 'C'
	for(i=0;i<3;i++)
	KM_LCD_Write_Cmd(0x10);
	
	ADC_CR2 &= ~(0x1<<30);	//Clear Trigger.
	KM_delayms(500);

}

void ADC_IRQHandler()
{
	
	TEMP_Value = ADC_DR;	//Collect data from ADC_DR.
	MY_DISPLAY(TEMP_Value);
}

int main()
{
	GPIOC_Init();	//Initializing PORTC.
	GPIOC_Config();	//PORTC configuration.
	STK_Init();
	LCD_Common();
	KM_ADC_Init();	//Initializing ADC.
	KM_LCD_Write_Str(str);
	KM_LCD_Write_Cmd(0x14>>12);
		while(1)
		{
		KM_ADC_Read();	//read ADC o/p from Potentiometer.
		}

	//return 0;
}

