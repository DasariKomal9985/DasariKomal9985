/*

Lab Experiment 4: Use �SW_ENT� and declare �counter� global variable. Your program should increment counter by one, 
every time switch is pressed. Note how the value of counter changes on each �ENTER SWITCH� press. 
Use debugger and add Counter to �Watch Expression� window. Does the value of counter increment by one always?
Note: Define counter as a global variable and in debug perspective use continuous refresh option 
(You will find Continuous Refresh button on top of the Expression Window). 
You can use step debugging or breakpoints to check the variable value.
Hint: To add variable to Expression Window, select and right click the variable name and select 
�Add Watch Expression�. To view Expression Window, click on View button from Keil menu bar and select Expressions.

*/

#define RCC_AHB1ENR *((int *)0x40023830)
#define GPIOC_MODER *((int *)0x40020800)
#define GPIOC_PUPDR *((int *)0x4002080c)
#define GPIOC_IDR *((int *)0x40020810)
	
int c;
void initial(void)
{
RCC_AHB1ENR |= 0x4;				//reading RCC_AHB1ENR register and setting 1st bit without disturbing others.
while(!(RCC_AHB1ENR & 0x4));  //wait untill 1st bit value 1 or clock is set.
}	


void config(void)
{

GPIOC_MODER &= 0xffcfffff;		//clearing 21 and 20 bitfield to enable portC
GPIOC_PUPDR &= 0xffcfffff;		//clearing 21 and 20 bitfield in GPIOC_PUPDR
GPIOC_PUPDR |= 0x00100000;		//set 21 and 20 bitfied to enable switch_enter in i/p direction.


}	

void delay(void)
{
int i=725000;
	for(;i>0;i--);
}

int main()
{

	initial();
	config();
		
	while(1)
	{
		if(!(GPIOC_IDR & (0x1<<10)))	
		{
			c++;
		delay();
		}	
	}
	
return 0;
}

