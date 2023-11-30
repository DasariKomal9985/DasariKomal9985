
#define RCC_AHB1ENR *((int *)0x40023830)
#define GPIOB_MODER *((int *)0x40020400) 
#define GPIOB_ODR *((int *)0x40020414)
void initial(void)
{
RCC_AHB1ENR |= 0X2;				//reading RCC_AHB1ENR register and setting 1st bit without disturbing others.
while(!(RCC_AHB1ENR & 0x2));  //wait untill 1st bit value 1 or clock is set.
}	

void config(void)
{
GPIOB_MODER &= 0xfcffffff;		//clearing 25 and 24 bit positions
GPIOB_MODER |= 0x01000000;		//loading 01 into 25 and 24 bits to set the mode as output
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
	GPIOB_ODR &= ~(0x1<<12);	//clearing 12th bit in GPIOB_ODR to ON buzzer.
	for(j=0;j<2;j++)					//delay 100ms.
		delay();
	
	GPIOB_ODR |= (0x1<<12);		//set 12th bit in GPIOB_ODR to OFF buzzer.
	for(j=0;j<2;j++)
		delay();
		
	}
return 0;
}
