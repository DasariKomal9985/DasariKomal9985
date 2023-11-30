/*  Write a function that takes two sorted integer arrays as input, and returns an array of integers from both arrays in sorted order, excluding duplicate numbers. 
Assume that the input arrays are sorted.
eg., array1 : 10,12,13,14,15,16
array2 : 9,12,15,19,20
output array3 : 9,10,12,13,14,15,16,19,20

*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *remove_dub(int *arr1,int *arr2,int n,int m);
int z;
int main()
{
	int a,b,n,m,i,*ptr;
	int *arr1;
	printf("enter n value:\n");
	scanf("%d",&n);
	arr1=(int *)malloc(n*sizeof(int));
	printf("enter 1st array:\n");
	for(i=0;i<n;i++)
	{
		printf("enter %d is  :",i+1);
		scanf("%d",&arr1[i]);
	}
	int *arr2;
	printf("enter m value:");
	scanf("%d",&m);
	arr2=(int *)malloc(m*sizeof(int));
	printf("enter 2nd array:\n");
	for(i=0;i<m;i++)
	{
		printf("enter %d is  :",i+1);
		scanf("%d",&arr2[i]);
	}
	ptr=remove_dub(arr1,arr2,n,m);
	printf("\n");
	for(i=0;i<z;i++)
	{
		printf("%d\t",ptr[i]);
	}
	return 0;
}



int *remove_dub(int *arr1,int *arr2,int n,int m)
{
	int i,j,l,temp;
	int *ptr=(int *)malloc((m+n)*sizeof(int));
	for(i=0;i<n;i++)
	{
		*(ptr+i)=*(arr1+i);
	}
	for(i=n,j=0;j<m;i++,j++)
	{
		*(ptr+i)=*(arr2+j);
	}
	l=m+n;
	for(i=0;i<l-1;i++)
	{
		for(j=0;j<l-i-1;j++)
		{
			if(ptr[j]>ptr[j+1])
			{
				temp=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=temp;
			}
		}
	}
	z=l;
	for(i=0;i<z;i++)
	{
		if(ptr[i]==ptr[i+1])
		{
			for(j=i+1;j<z;j++)
			{
				temp=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=temp;
			}
			z--;
			i--;
		}
	}
	return ptr;
}
