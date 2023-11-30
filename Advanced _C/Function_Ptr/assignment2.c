//Rewrite the calculator program using an array of function pointers



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
	char c;
	int a,b,n;
	printf("enter 1 st element:");
	scanf("%d",&a);
	getchar();
	printf("enter 2 nd element:");
	scanf("%d",&b);
	getchar();
	printf("enter character :");
	scanf("%c",&c);
	int (*ptr[5])(int,int)={add,sub,mul,div,mod};
	switch(c)
	{
		case'+':printf("addition is         :%d\n",ptr[0](a,b));break;
		case'-':printf("subraction is       :%d\n",ptr[1](a,b));break;
		case'*':printf("multiplaction is    :%d\n",ptr[2](a,b));break;
		case'/':printf("division is         :%d\n",ptr[3](a,b));break;
		case'%':printf("modulas is          :%d\n",ptr[4](a,b));break;
		default:printf("enter valid character");
	}
}


