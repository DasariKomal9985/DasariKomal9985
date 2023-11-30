
//1) create an integer dynamically ,read and print its value



#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr;
	ptr=(int*)malloc(1*sizeof(int));
	printf("enter an integer:");
	scanf("%d",ptr);
	printf("\n\n");
	printf("out put is:");
	printf("\n\n");
	printf("%d\n",*ptr);

}
