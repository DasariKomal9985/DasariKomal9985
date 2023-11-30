/*4) read an integer and print it back in complete number name expansion with place values as below:

eg., 458
output : four hundred fifty eight */
#include<stdio.h>
char *p[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","ninteen"};
char *q[]={"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninty"};
char *r[]={"hundred","thousand"};
int tenths(int n)
{
    int d;
    if(n<20)
    {
	printf("%s ",p[n]);
    }
    else if(n%10==0)
    {
	d=n/10;
	printf("%s",q[d-2]);
    }
    else if(n>20)
    {
	d=n/10;
	printf("%s ",q[d-2]);
	d=n%10;
	printf("%s",p[d]);
    }
}

int hundreds(int n)
{
    int d;
    if(n%100==0)
    {
	d=n/100;
	tenths(d);
	printf("%s",r[0]);
    }
    else 
    {
	d=n/100;
	tenths(d);
	printf("%s ",r[0]);
	d=n%100;
	tenths(d);
    }

}

int thousands(int n)
{
    int d;
    if(n%1000==0)
    {
	d=n/1000;
	tenths(d);
	printf("%s",r[1]);
    }
    else 
    {
	d=n/1000;
	tenths(d);
	printf("%s ",r[1]);
	d=n%1000;
	if(d>=100)
	hundreds(d);
	else 
	    tenths(d);
    }
}

int main()
{
    int n;
    printf("enter a number:");
    scanf("%d",&n);
    if(n<100)
    {
	tenths(n);
    }
    else if(n<1000)
    {
	hundreds(n);
    }
    else if(n<10000)
    {
	thousands(n);
    }

}


