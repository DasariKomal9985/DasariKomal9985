// implement itoa function ( take an integer and store it in a string and return the string).
//String can be returned as the base address of the array ( return str). The return type of function will be char *


#include <stdio.h>
#include<stdlib.h>
char *mystritoa(int n)
{
    int t=0,i=0;
    char x[1000];
    char *s=x;
    while(n)
    {   
        t=n%10;
        *(s+i)=(char)t+48;
        n=n/10;
        i++;
    }   
    *(s+i)='\0';
    for(int k=0;k<i/2;k++)
    {   
        t=*(s+k);
        (s+k)=(s-k+i-1);
        *(s-k+i-1)=t;
    }   
    return s;
}

int main()
{
    int a;
    char *p; 
    printf("enter a number :");
    scanf("%d",&a);
    p=mystritoa(a);
    printf("int to str : %s",p);
    return 0;
}
