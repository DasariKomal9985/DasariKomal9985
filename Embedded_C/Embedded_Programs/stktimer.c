
#define RCC_AHB1ENR *((int *)0x40023830)
#define GPIOB_MODER *((int *)0x40020400) 
#define GPIOB_ODR *((int *)0x40020414)
#define STK_CTRL *((int *)0xE000E010)
#define STK_LOAD *((int *)0xE000E014)
#define STK_VAL *((int *)0xE000E018)

void initial(void)
{
	//portB enabling
RCC_AHB1ENR |= 0X2;				//reading RCC_AHB1ENR register and setting 1st bit without disturbing others.
while(!(RCC_AHB1ENR & 0x2));  //wait untill 1st bit value 1 or clock is set.

	//STK initialization
STK_CTRL |= 0x05;	
STK_VAL = 0x123;
}	

void config(void)
{
	//Red LED
GPIOB_MODER &= 0xf3ffffff;		//clearing 27 and 26 bit positions
GPIOB_MODER |= 0x04000000;		//loading 01 into 27 and 26 bits to set the mode as output

}	
// milli seconds delay.
void delayms(int x)
{
	
STK_LOAD = x*16000;
while((STK_CTRL & (0X1<<16)) == 0);
	
}

//micro seconds delay.
void delayus(int x)
{
	STK_LOAD = x*16;
	while((STK_CTRL & (0X1<<16)) == 0);
}

//minimum delay possible
void delaymin()
{
	STK_LOAD = 0x1;
	while((STK_CTRL & (0X1<<16)) == 0);
}

//maximum delay possible
void delaymax()
{
	STK_LOAD = 0xffffffff;
	while((STK_CTRL & (0X1<<16)) == 0);
}

int main()
{
	initial();
	config();

	while(1)
	{
	GPIOB_ODR &= ~ (0x1<<13);	//Red LED ON
	//delayms(100);
	delaymin();
	//delaymax();
		
	GPIOB_ODR |= (0x1<<13);		//Red LED OFF
	//delayms(100);
	delaymin();
	//delaymax();
	}
	
	
return 0;
}

