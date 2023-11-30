// WAP whether a number is ODD or EVEN using bitwise.


#include<stdio.h>
#define oddeve(a) a&0x01
int main()
{
	int a;
	printf("enter any number");
	scanf("%d",&a);
	printf("%d\t",oddeve(a)?1:0);
	if(oddeve(a)==1)
		printf("---is odd\n ");
	else
		printf("---is even\n");
}

