//WAP to count the bits set (bit value 1 ) in an integer? Find out and compare different possibilities?

#include<stdio.h>
#define CHECKK(a,p) a&0x1<<p

int main()
{
	int x,p,c=0,n,i;
	printf("Enter a number:\n");
	scanf("%d",&x);
	i=n=x;

	//possibility 1:
	for(p=7;p>=0;p--)
	{
		CHECKK(x,p)?printf("1"),c++:printf("0");
	}

	printf("\nNo.of bits SET = %d\n",c);

	//possibility 2:
	c=0;
	while(n>0)
	{
		n=n&(n-1);
		c++;
	}

	printf("\nNo.of bits SET = %d\n",c);

	//possibility 3:
	c=0;
	while(i)
	{
		if(i&0x20000000)
		{
			printf("1\n");
			c++;}

		i=i<<1;
	}
	printf("No.of bits SET = %d\n",c);
	return 0;
}
k
