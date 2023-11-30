//WAP multiply a number by 9 using bit shift.


#include<stdio.h>
int main()
{
	int a,n;
	printf("enter multiple of 9 : ");
	scanf("%d",&a);
	n=(a<<3)+a;
	printf("%d\n",n);
}
