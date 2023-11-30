
#include<stdio.h>
extern int stock;
int sell()
{
	int b;
	printf("how much quantity do you want?\n");
	scanf("%d",&b);
	if(b>stock)
		printf("sorry the stock is not avilable\n");
	else
		stock = stock - b;
}

