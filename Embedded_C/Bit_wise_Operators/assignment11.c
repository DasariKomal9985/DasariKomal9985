//WAP whether a number is a power of 2 or not?

#include<stdio.h>
int main()
{
	int a,count=0;
	printf("enter number");
	scanf("%d",&a);
	while(a)
	{
		if(a&0x80)
		{
			count++;
		}
	a=a<<1;
	}
	if(count==1)
		printf("is power of 2");
	else
		printf("not a power of 2");
	return 0;
}
