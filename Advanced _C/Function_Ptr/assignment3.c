/*"Write the calculator program using a function that accepts a function pointer and the operand values as arguments and invokes it. In the main function, simply invoke this function by sending the appropriate function address, based on the operator chosen.
eg.,
in main
case '+' :invokeptr(add , x,y);


invokeptr(int (*fptr) (int,int) , int x, int y)
{
printf(""%d\n"",fptr(x,y));
}"
*/


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

int cal(int(*ptr)(int,int),int a,int b)
{
	return (*ptr)(a,b);
}


#include<stdio.h>
int cal(int(*ptr)(int,int),int a,int b);
int main()
{
	int a,b;
	char c;
	printf("enter 1st element:");
	scanf("%d",&a);
	printf("enter 2nd element:");
	scanf("%d",&b);
	getchar();
	printf("enter character:");
	scanf("%c",&c);
	switch(c)
	{
		case'+':printf("addition is       :%d\n",cal(add,a,b));break;
		case'-':printf("subraction is     :%d\n",cal(sub,a,b));break;
		case'*':printf("multiplaction is  :%d\n",cal(mul,a,b));break;
		case'/':printf("division is       :%d\n",cal(div,a,b));break;
		case'%':printf("modulas is        :%d\n",cal(mod,a,b));break;
	}
}
