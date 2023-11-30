


#define RCC_AHB1ENR *((int *)0x40023830)
#define GPIOB_MODER *((int *)0x40020400) 
#define GPIOB_ODR *((int *)0x40020414)
#define GPIOC_MODER *((int *)0x40020800)
#define GPIOC_PUPDR *((int *)0x4002080c)
#define GPIOC_IDR *((int *)0x40020810)
	

void initial(void)
{
RCC_AHB1ENR |= 0x2;				//reading RCC_AHB1ENR register and setting 1st bit without disturbing others.
while(!(RCC_AHB1ENR & 0x2));  //wait untill 1st bit value 1 or clock is set.

RCC_AHB1ENR |= 0x4;				//reading RCC_AHB1ENR register and setting 1st bit without disturbing others.
while(!(RCC_AHB1ENR & 0x4));  //wait untill 1st bit value 1 or clock is set.
}	


void config(void)
{
GPIOB_MODER &= 0xc3ffffff;		//clearing 29 to 26 bit positions
GPIOB_MODER |= 0x14000000;		//loading '0101' into 29 to 26 bits to set the mode of LEDs as output
GPIOC_MODER &= 0xfff0ffff;		//clearing 19 to 16 bitfield to enable portC
GPIOC_PUPDR &= 0xfff0ffff;
GPIOC_PUPDR |= 0x00050000;
GPIOB_ODR |= (0x1<<13);
GPIOB_ODR |= (0x1<<14);
}	

void delay(void)
{
int i=125000;
	for(;i>0;i--);
}

int main()
{
	int j;
	initial();
	config();
		
	while(1)
	{
		if(!(GPIOC_IDR & (0x1<<9))) 	//
		{
		GPIOB_ODR &= ~(0x1<<14);	//clearing 14th bit to ON green LED.	
			delay();
		}
		else;	
		if(!(GPIOC_IDR & (0x1<<8)))	
		{
			GPIOB_ODR &= ~(0x1<<13);	//clearing 13th bit to ON red LED.
		delay();
		}	
	}
	
return 0;
}

