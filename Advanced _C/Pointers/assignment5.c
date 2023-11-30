/*Implement the below functions 

strlen*/


int MyString(char *str1)
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
	printf("enter string");
	scanf("%s",str1);//taking string
	x=MyString(str1);//calling function string
	printf("length of the givin is %d\n",x);//printing return value of str

}
