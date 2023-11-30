
#include<stdio.h>
extern int stock;
int purchase()
{
	int x,n=2000;
	printf("how much stock do you want?\n");
	scanf("%d",&x);
	if(x>n)
		printf("sorry out of godam capacity\n");
	else
		stock = stock+x;
}

