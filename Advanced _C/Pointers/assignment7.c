/*Implement the below functions 

strcmp*/

//string compare
int MyString(char *str1,char *str2,int x)
{
int i;
for(i=0;i<x;i++)
{
if(str1[i]==str2[i])
return 1;
else 
return 0;
}
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



//main function
#include<stdio.h>
int main()
{
int x,y;
char str1[10];
char str2[10];
printf("enter string");
scanf("%s",str1);
x=MyStrlen(str1);
scanf("%s",str2);
y=MyString(str1,str2,x);
if(y==1)
printf("Same");
else
printf("Differewnt");
return 0;
}
