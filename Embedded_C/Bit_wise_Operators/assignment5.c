//WAP implement addition functionality with out using ADD('+') Operator.

#include<stdio.h>
#define add(a,b) (a-(~b))-1
int main()
{
	int a,b;
	printf("enter frist operand  :");
	scanf("%d",&a);
	printf("enter seacond operand:");
	scanf("%d",&b);
	printf("%d",add(a,b));
}
 
