//Write a program to replace a given character by another character in a string


//string length
int MyStrlen(char *str1)
{
	int i,count=0;
	while(*str1 != '\0')//until string will be zero
	{
		str1++;//string adderss will be increased
		count++;//counter
	}
	return count;//return count
}





#include<stdio.h>
int main()
{
int i,x,a;
char b;
char str[10];
printf("enter string");
scanf(" %s",str);
printf("enter which character you replace");
scanf(" %d",&a);
printf("enter which character you want");
scanf(" %c",&b);
x=MyStrlen(str);
for(i=0;i<x;i++)
{
if(i==a)
str[i]=b;
}
printf("after changed the name is %s",str);
}

