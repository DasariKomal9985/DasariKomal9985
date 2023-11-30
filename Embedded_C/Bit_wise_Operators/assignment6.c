//. WAP implement XOR functionality with out using XOR(^) operator.


#include<stdio.h>
#define xor(a,b) (~a&b)|(a&~b)
int main()
{
int a,b;
printf("enter frist operand");
scanf("%d",&a);
printf("enter second oprend");
scanf("%d",&b);
printf("%d",xor(a,b));
}
