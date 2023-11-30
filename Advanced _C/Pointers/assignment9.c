/*Implement the below functions 
strcat*/

//string congartation
void MyStrcat(char *str1,char *str2,int x)
{
int i;
for(i=0;i<x;i++)
{
str1[x+i]=str2[i];
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



#include<stdio.h>
int main()
{
int x;
char str1[10];
char str2[10];
printf("enter string ");
scanf("%s",str1);//enter frist string 
printf("frist string is %s\n",str1);
x=MyStrlen(str1);//finding length of givin string
scanf("%s",str2);//enter seacond string
printf("seacond string is %s\n",str2);
MyStrcat(str1,str2,x);//calling function parameters string 1 string 2 and x value
printf("adding of frist and seacond string is %s\n",str1);//printing seacond string
}


