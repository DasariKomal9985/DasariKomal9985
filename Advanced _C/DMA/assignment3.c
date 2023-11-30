//create a string dynamically, copy a string constant to it ( "Kernel"). Create another string dynamically. Copy the first string to second string.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *ptr1;
	char *ptr2;
	ptr1=(char*)malloc(sizeof(char));
	ptr2=(char*)malloc(sizeof(char));
	printf("enter 1st string:");
	scanf("%s",ptr1);
	printf("enter 2nd string:");
	scanf("%s",ptr2);
	strcpy(ptr1,ptr2);
	printf("%s\t",ptr1);
}
