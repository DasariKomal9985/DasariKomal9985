// WAP Check if the 20th bit of a 32-bit integer is on or off?


#include<stdio.h>
int main()
{
	int a;
	printf("enter number");
	scanf("%d",&a);
	if(a&0x80<<20)
	{
		printf("ON\n");
	}
	else
	{
		printf("OFF\n");
	}
}


