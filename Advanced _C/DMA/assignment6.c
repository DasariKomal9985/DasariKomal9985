/*Write a function, that takes two strings as input and concatenates only the first n characters from first string and first m characters from second string and makes a new string.
eg., input str1 = "kernel masters", str2 = "raayan systems", n = 3, m = 5
output : kerraaya*/

#include<stdio.h>
#include<stdlib.h>
char fun(char*,char*,int,int);
int main()
{
	int n,a,b,m;
	printf("enter n value:");
	scanf("%d",&n);
	char *str1=(char*)calloc(n,sizeof(char));
	printf("enter m value:");
	scanf("%d",&m);
	char *str2=(char*)calloc(m,sizeof(char));
	printf("enter string1:");
	scanf("%s",str1);
	printf("enter string2:");
	scanf("%s",str2);
	printf("enter how many elements you want in string1:");
	scanf("%d",&a);
	printf("enter how many elements you want in string2:");
	scanf("%d",&b);
	fun(str1,str2,a,b);
	printf("changed string is :%s\n",str1);
}
char fun(char* str1,char* str2,int a,int b)
{
	int i,j;
	for(i=a,j=0;j<b;j++,i++)
	{
		str1[i]=str2[j];
	}
}





