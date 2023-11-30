/*Write a function that takes a main string and two sub strings (need not be same length), and replace every occurrence of first substring with the second substring in main string and return a new string as output.

eg., input : kernel  e   xxx

output: kxxxrnxxxl
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char exchange(char *ptr1,char *ptr2,char *ptr3);
int main()
{
	int n,x,y;
	char a;
	char *ptr1;
	char *ptr2;
	char *ptr3;
	printf("enter how many characters you need:");
	scanf("%d",&n);
	ptr1=(char*)malloc(n*sizeof(char));
	ptr2=(char*)malloc(10*sizeof(char));
	ptr3=(char*)malloc(10*sizeof(char));
	printf("enter any string:");
	scanf(" %[^\n]s",ptr1);
	printf("enter sub-string:");
	scanf(" %[^\n]s",ptr3);
	printf("enter replaced string:");
	scanf(" %[^\n]s",ptr2);
	x=strlen(ptr1);
	y=strlen(ptr2);
	exchange(ptr1,ptr2,ptr3);
	printf("changed string is :%s\n",ptr1);
}
char exchange(char *ptr1,char *ptr2,char *ptr3)
{
	int i;
	char *ptr4;
	char *ptr5;
	ptr4=(char*)malloc(50*sizeof(char));
	ptr5=(char*)malloc(50*sizeof(char));
	while(strstr(ptr1,ptr3)!=NULL)
	{
	ptr4=strstr(ptr1,ptr3);
	strcpy(ptr5,ptr4);
	*(ptr1+(ptr4-ptr1))='\0';
	strcat(ptr1,ptr2);
	strcat(ptr1,(ptr5+strlen(ptr3)));
	}
}
