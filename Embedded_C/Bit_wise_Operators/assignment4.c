//WAP implement subtraction functionality with out using SUB('-') Operator.    

#include<stdio.h>
#define sub(a,b) a+(~b+1)
int main()
{
	int a,b;
	printf("enter frist operand  :");
	scanf("%d",&a);
	printf("enter seacond operand:");
	scanf("%d",&b);
	sub(a,b);
//	if(a<b)
//		printf("-%d",sub(a,b));
//	else
//		printf("%d",sub(a,b));
	printf("%d",sub(a,b));
}
