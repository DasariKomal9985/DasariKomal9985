/*Write the calculator program using a function that accepts an array of function pointers and the operand values and operator character as arguments and invokes appropriate function based on the character. In main function, simply invoke this function by sending the array and operator character and operands as input.
eg.,
in main
case '+' :invokeptr( fparr, x,y, ch);


invokeptr(int (*fptr[]) (int,int) , int x, int y ,char ch)
{
//based on ch value, choose which index to apply on fptr and invoke the function
}
*/



#include<stdio.h>
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



int invokeptr(int(*fptr[5])(int,int),int a,int b,char c)
{
switch(c)
{
case'+':printf("addation is          :%d\n",fptr[0](a,b));break;
case'-':printf("subraction is        :%d\n",fptr[1](a,b));break;
case'*':printf("multiplaction is     :%d\n",fptr[2](a,b));break;
case'/':printf("division is          :%d\n",fptr[3](a,b));break;
case'%':printf("modulas is           :%d\n",fptr[4](a,b));break;
default:printf("enter valid character");
}
}




int invokeptr(int(*fptr[5])(int,int),int a,int b,char c);
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
int(*fptr[5])(int,int)={add,sub,mul,div,mod};
invokeptr(fptr,a,b,c);
}
