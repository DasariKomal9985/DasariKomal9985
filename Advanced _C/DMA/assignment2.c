// create a string dynamically, read and print its value


#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *ptr;
	int i,n;
	ptr=(char*)malloc(sizeof(char));
	printf("enter string");
	scanf("%s",ptr);
	printf("enterd string is : %s",ptr);
	free(ptr);
	return 0;
}
