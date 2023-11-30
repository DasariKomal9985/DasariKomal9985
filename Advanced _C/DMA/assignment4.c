//Create a dynamic array of integers. Take input from user , sort the array and display the output


#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr;
	int i,j,temp,n;
	printf("enter how many elements");
	scanf("%d",&n);
	ptr=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",ptr+i);
	}
	printf("\n\n");
	printf("givin matrix is :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",ptr[i]);
	}
	printf("\n\n");
	printf("asending order is  :");
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(ptr[j]>ptr[j+1])
				{
				temp=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=temp;
				}
		}
	}
	for(j=0;j<n;j++)
	{
	printf("%d\t",ptr[j]);
	}
	printf("\n\n");
	printf("desending order is :");
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(ptr[j]<ptr[j+1])
				{
				temp=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=temp;
				}
		}
	}
	for(j=0;j<n;j++)
	{
	printf("%d\t",ptr[j]);
	}

	
	return 0;
}
