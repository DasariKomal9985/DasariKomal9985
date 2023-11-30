//RCC
#define RCC_APB2ENR *((int *)0x40023844)	//To enable system confirguration
#define RCC_AHB1ENR *((int *)0x40023830)

//GPIO
#define GPIOB_MODER *((int *)0x40020400) 
#define GPIOB_ODR *((int *)0x40020414)
#define GPIOC_MODER *((int *)0x40020800)
#define GPIOC_PUPDR *((int *)0x4002080c)


#define SYSCFG_EXTICR3 *((int *)0x40013810)

//EXTI
#define EXTI_IMR *((int *)0x40013c00)
#define EXTI_FTSR *((int *)0x40013c0c)
#define EXTI_PR *((int *)0x40013c14)
#define EXTI15_10 *((int *)0x000000E0)	
#define NVIC_ISER1 *((int *)0xE000E104)

int count,flag;

void initial(void)
{

//portB clock enable
RCC_AHB1ENR |= 0x2;				//reading RCC_AHB1ENR register and setting 1st bit without disturbing others.
while(!(RCC_AHB1ENR & 0x2));  //wait untill 1st bit value 1 or clock is set.

//portC clock enable
RCC_AHB1ENR |= 0x4;				//reading RCC_AHB1ENR register and setting 2nd bit without disturbing others.
while(!(RCC_AHB1ENR & 0x4));  //wait untill 2nd bit value 1 or clock is set.

}	

//Interrupt enable to Enter Switch.
void SWITCH_INT_EN(void)
{
RCC_APB2ENR |= 0x00004000;	//enabling system configuration clock. 
SYSCFG_EXTICR3 |= 0x00000200;	//enabling pc10 as external interrupt.
EXTI_IMR |= 0x00000400; //Set PC10 when interrupt occurs. (or) enable pc10 mask.
EXTI_FTSR |= 0x00000400; //Set PC10 in falling edge trigger.
NVIC_ISER1 |= 0x00000100; //Enable 40th interrupt pin NVIC.

}


void config(void)
{
	GPIOB_MODER &= 0xf3ffffff;		//clearing 27 and 26 bit positions
	GPIOB_MODER |= 0x04000000;		//loading 01 into 27 and 26 bits to set the RED LED mode as output
	GPIOC_MODER &= 0xffcfffff;		//clearing 21 and 20 bitfield to enable portC
	GPIOC_PUPDR &= 0xffcfffff;		//clearing 21 and 20 bitfield in GPIOC_PUPDR
	GPIOC_PUPDR |= 0x00100000;		//set 21 and 20 bitfied to enable switch_enter in i/p direction.
	GPIOB_ODR |= (0x1<<13);				//OFF PB13(RED LED);
}	

/*
void delay(void)
{
int i=725000;
	for(;i>0;i--);
}
*/

int main()
{
	
	initial();
	config();
	SWITCH_INT_EN();
	
	while(1)
	{
			if(flag==1)
				GPIOB_ODR &= ~(0x1<<13);
			else
				GPIOB_ODR |= (0x1<<13);
	}
return 0;
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI_PR & 0x400)
	{
	flag=1;
	count++;
	EXTI_PR |= 0x400;
	}
}

