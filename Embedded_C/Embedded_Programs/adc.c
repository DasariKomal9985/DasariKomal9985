
#define RCC_AHB1ENR *((int *)0x40023830)
#define RCC_APB2ENR *((int *)0x40023844)
#define GPIOC_MODER *((int *)0x40020800)
#define STK_CTRL *((int *)0xE000E010)
#define STK_LOAD *((int *)0xE000E014)
#define STK_VAL *((int *)0xE000E018)
#define ADC_SMPR1 *((int *)0x4001200c)
#define ADC_SQR3 *((int *)0x40012034)
#define ADC_CR1 *((int *)0x40012004)
#define ADC_CR2 *((int *)0x40012008)
#define ADC_SR *((int *)0x40012000)
#define ADC_DR *((int *)0x4001204c)

int POT_Value;	//global variable.

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
GPIOC_MODER &= 0xfffffff3;	//clearing bits 3&2 in GPIOC_MODER.
GPIOC_MODER |= 0x0000000c;	//set bits 3&2 in GPIOC_MODER (enable PC1 in Analog direction).
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
	//ADC_SMPR1 |= 0x07;	//Smapling SMP10 highest cycles.
	//ADC_SMPR1 = 0x38;	//Smapling SMP11 highest cycles.
	ADC_SQR3 |= 0x0b;	//load '1011' in 0-4 positions to set ADC_11 as 1st conversion.
	ADC_CR1 &= ~(0x3<<24);	//load '00'in 24-25 positions to set 12th bit resolution.
	ADC_CR2 |= 0x1<<10;	//set 10th bit (EOC selection).
	ADC_CR2 |= 0x1;	//set 0th bit (ADON to turn ON ADC)
}

void KM_ADC_Read(void)
{
	ADC_CR2 |= (0x1<<30);	//Start Conversion (SWSTRT enabling).
	while(!(ADC_SR & 0x2))
	{	
	;
	}
	//if conversion complete EOC bit will set.
	POT_Value = ADC_DR;	//Collect data from ADC_DR.
	ADC_CR2 &= ~(0x1<<30);	//Clear Trigger.
	KM_delayms(500);

}

int main()
{
	GPIOC_Init();	//Initializing PORTC.
	GPIOC_Config();
	STK_Init();
	KM_ADC_Init();	//Initializing ADC.
		while(1)
		{
		KM_ADC_Read();	//read ADC o/p from Potentiometer.
		}

	//return 0;
}

