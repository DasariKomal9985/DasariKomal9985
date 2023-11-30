//Implement atoi function ( to take a numerical string and return integer





int MyStratoi(char *str,int x)
{
int i,con=0,quo=0,garb=0;
int rem=0;
char temp;
for(i=0;i<x;i++)
{
temp=str[i];
garb=(garb*10)+temp-48;
}
return garb;
}

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
int MyStratoi(char *str,int x);
int main()
{
int g,x;
char str[10];
printf("enter string");
scanf("%s",str);
printf("givin value is %s\n",str);
x=MyStrlen(str);
g=MyStratoi(str,x);
printf("AtoI value is %d\n",g);
}


