
//RCC
#define RCC_APB2ENR *((int *)0x40023844)	
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
//#define EXTI15_10 *((int *)0x000000E0)	
#define NVIC_ISER0 *((int *)0xE000E100)
#define NVIC_ISER1 *((int *)0xE000E104)


int Rflag,Gflag;

void initial(void)
{

//portB clock enable
RCC_AHB1ENR |= 0x2;				//reading RCC_AHB1ENR register and setting 1st bit without disturbing others.
while(!(RCC_AHB1ENR & 0x2));  //wait untill 1st bit value 1 or clock is set.

//portC clock enable
RCC_AHB1ENR |= 0x4;				//reading RCC_AHB1ENR register and setting 2nd bit without disturbing others.
while(!(RCC_AHB1ENR & 0x4));  //wait untill 2nd bit value 1 or clock is set.

}	

//Interrupt enable to SwitchUP & SwitchDN
void SWITCH_UPDN_INT_EN(void)
{
RCC_APB2ENR |= 0x00004000;	//enabling system configuration clock. 
SYSCFG_EXTICR3 |= 0x00000022;	//enabling pc9 & pc8 as external interrupts.
EXTI_IMR |= 0x00000300; //Enable pc9 & pc8 mask.
EXTI_FTSR |= 0x00000300; //Set PC10 in falling edge trigger.
NVIC_ISER0 |= 0x00800000; //Enable 23th interrupt pin NVIC. (enableing EXTI Line[9:5] interrupts)
}


//Both LEDs and Switches Configuration.
void config(void)
{
	GPIOB_MODER &= 0xc3ffffff;		//clearing 29 to 26 bit positions
	GPIOB_MODER |= 0x14000000;		//loading '0101' into 29 to 26 bits to set the mode of LEDs as output
	GPIOC_MODER &= 0xfff0ffff;		//clearing 19 to 16 bitfield to enable portC
	GPIOC_PUPDR &= 0xfff0ffff;		
	GPIOC_PUPDR |= 0x00050000;		//Enabling Pullup direction for both SW_UP and SW_DN.
	GPIOB_ODR |= (0x1<<13);				//OFF Red LED.
	GPIOB_ODR |= (0x1<<14);				//ON Red LED.
}


int main()
{	
	initial();
	config();
	SWITCH_UPDN_INT_EN();
	
	while(1)
	{
			if(Rflag==1)
				GPIOB_ODR &= ~(0x1<<13);	//RED LED ON
			if(Gflag==1)
				GPIOB_ODR &= ~(0x1<<14);	//GREEN LED ON
	}
return 0;
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI_PR & 0x100)
	{
	Rflag=1;
	EXTI_PR |= 0x100;
	}
	else if(EXTI_PR & 0x200)
	{
	Gflag=1;
	EXTI_PR |= 0x200;
	}
}

