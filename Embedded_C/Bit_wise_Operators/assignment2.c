//WAP print binary?


#include<stdio.h>
#define call(a,p) a&0x1<<p
int main()
{
	int a,p;
	printf("enter number");
	scanf("%d",&a);
	for(p=7;p>=0;p--)
	{
		if(call(a,p))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
}
