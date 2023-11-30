#include "HEAD.h"	//user define library for all physical addresses and function declarations.

unsigned int TEMP_Value;	//global variable.
char str[20]="Temperature"; //String to display at begining.

void GPIOC_Init()
{
RCC_AHB1ENR |= 0x4;				//reading RCC_AHB1ENR register and setting 1st bit without disturbing others.
while(!(RCC_AHB1ENR & 0x4));  //wait untill 1st bit value 1 or clock is set.
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
}

void KM_ADC_Read(void)
{
	int i;
	ADC_CR2 |= (0x1<<30);	//Start Conversion (SWSTRT enabling).
	while(!(ADC_SR & 0x2))
	{	
	;
	}
	//if conversion complete EOC bit will set.
	TEMP_Value = ADC_DR;	//Collect data from ADC_DR.
	TEMP_Value /= 10;	//Temperature in C = Vout/10ma
	
	KM_delayms(1);
	KM_LCD_Write_Data((TEMP_Value/10)+48);	
	KM_LCD_Write_Data((TEMP_Value%10)+48);
	KM_LCD_Write_Data('C');
	for(i=0;i<3;i++)
	KM_LCD_Write_Cmd(0x10);
	
	//KM_LCD_Write_Cmd(0x10);

	
	ADC_CR2 &= ~(0x1<<30);	//Clear Trigger.
	KM_delayms(500);

}

int main()
{
	GPIOC_Init();	//Initializing PORTC.
	GPIOC_Config();	//PORTC configuration.
	PORTB_initial();	//PORTB Initialization.
	PORTB_config();	//PORTB configuration.
	STK_Init();
	KM_LCD_Init();
	KM_ADC_Init();	//Initializing ADC.
	KM_LCD_Write_Str(str);
	KM_LCD_Write_Cmd(0x14>>12);
		while(1)
		{
		KM_ADC_Read();	//read ADC o/p from Potentiometer.
		}

	//return 0;
}


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
                                                                             


