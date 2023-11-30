//read an integer number, display the number as a number name expansion.
//eg., 458 : four five eight


#include<stdio.h>
int main()
{
	int n,i,j,quo=0,rem=0;
	printf("enter an element:");
	scanf("%d",&n);
	char *arr[]={};
	char *str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	for(i=0;n!=0;i++)
	{
		rem=n%10;
		arr[i]=str[rem];
		n=n/10;
	}
	for(j=i-1;j>=0;j--)
	{
		printf("%s\t",arr[j]);
	}
}

