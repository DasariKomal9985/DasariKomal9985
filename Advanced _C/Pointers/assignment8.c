/*Implement the below functions 
strrev*/


//string reverse
void MyStrrev(char *str1,int x)
{
char temp;
int i;
for(i=0;i<x;i++,x--)
{
temp=str1[i];//coping of frist index to the temporary value 
str1[i]=str1[x-1];//coping of last value to the frist index value
str1[x-1]=temp;//coping of temporary value to the last index vlaue
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
int x;
char str1[10];
printf("enter string ");
scanf("%[^\n]s",str1);//enter frist string 
printf("frist string is %s\n",str1);
x=MyStrlen(str1);//finding length of givin string
MyStrrev(str1,x);
printf("reversed string is %s\n",str1);//printing seacond string
}

