//1)Create a character pointer array, initialise the pointers to read only strings. Sort the array and print.


#include<stdio.h>
#include<string.h>
int main()
{
	int i,j;
	char *temp;
	char *arr[12]={"komal","sandeep","vamsi","vara","ravi","prakesh","rambant","probro","rajsh","raksh","vinay","anji"};
	for(i=0;i<12;i++)
	{
		printf("%s\t",arr[i]);
	}
	printf("\n\n");
	for(i=0;i<12;i++)
	{
		for(j=0;j<12-i-1;j++)
		{
			if(strcmp(arr[j],arr[j+1])>0)
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<12;i++)
	{
		printf("%s\t",arr[i]);
	}
}

