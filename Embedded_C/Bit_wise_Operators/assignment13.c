/*Write a functionsetbits(x,p,n,y)that return x with then bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
e.g. if x = 10101010 (170 decimal) and y = 10100111 (167 decimal) and n = 3 and p = 6 then
you need to strip off 3 bits of y (111) and put them in x at position 10xxx010 to get answer
10111010. Your answer should print out the result in binary form although input can be in
decimal form.
Your output should be like this:
x = 10101010 (binary)
y = 10100111 (binary)
setbits n = 3, p = 6 gives x = 10111010 (binary).

*/
#include<stdio.h>
#define binary(a) while(a){(a&0x80000000)?printf("1"):printf("0");a=a<<1;}
int funsetbits(int,int,int,int);
int main()
{
	int x,y,n,p,t,q;
	printf("Enter x value and position p to change:\n");
	scanf("%d%d",&x,&p);
	printf("Enter y value and no.of bits n to select:\n");
	scanf("%d%d",&y,&n);

	t=x;
	printf("x=\n");
	binary(t);
	q=y;
	printf("\ny=\n");
	binary(q);

	x=funsetbits(x,p,y,n);
	printf("\nFinal x in decimal = %d\n",x);
	t=x;
	printf("Final x in binary = ");
	binary(t);
	printf("\n");

	return 0;
}


int funsetbits(int x,int p,int y,int n)
{
	y=(~(0xffffffff<<n)&y)<<(p-n);
	x=(x&(~y))|y;

	return x;
}

