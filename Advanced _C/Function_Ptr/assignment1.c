//Write the calculator program using function pointers for add, sub, mul, div and mod functions, using a single function pointer

int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int div(int a,int b)
{
	return a/b;
}
int mod(int a,int b)
{
	return a%b;
}

#include<stdio.h>
int main()
{
	int a,b;
	char c;
	printf("enter 1 st element:");
	scanf("%d",&a);
	getchar();
	printf("enter 2 nd element:");
	scanf("%d",&b);
	getchar();
	printf("enter character :");
	scanf("%c",&c);
	int (*ptr1)(int,int);
	switch(c)
	{
		case'+':ptr1=add;printf("addation is :     %d\n",ptr1(a,b));
			break;
		case'-':ptr1=sub;printf("subraction is :   %d\n",ptr1(a,b));
			break;
		case'*':ptr1=mul;printf("multiplaction is :%d\n",ptr1(a,b));
			break;
		case'/':ptr1=div;printf("division is :     %d\n",ptr1(a,b));
			break;
		case'%':ptr1=mod;printf("modulas is :      %d\n",ptr1(a,b));
			break;
	}
}

