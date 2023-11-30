//WAP Swap any two numbers using bitwise operators. How does it work?


#include<stdio.h>
int main()
{
	int a,b,c=0;
	printf("enter frist oprend :");
	scanf("%d",&a);
	printf("enter second oprend:");
	scanf("%d",&b);
	c=a^b;
	b=c^b;
	a=a^c;
	printf("swaping is %d\t%d\n",a,b);
}
