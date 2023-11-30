/*Search for an element in a two dimentional array, and print its position - as row and column numbers. write a search function that will receive the array and return row and column indexes as output.*/




#include<stdio.h>
int Search(int a,int b,int c,int mat1[a][b],int *arr1,int *arr2);
int main()
{
	int i,j,a,b,c,x,row,col,arr1[10],arr2[10];
	printf("enter no of rows:\n");
	scanf("%d",&a);
	printf("enter no of cols:\n");
	scanf("%d",&b);
	row=a;
	col=b;
	int mat1[a][b];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&mat1[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	printf("final matrix is :\n");
	printf("\n\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",mat1[i][j]);
		}
		printf("\n");
	}
	printf("enter element you want to search:");
	scanf("%d",&c);
	x=Search(a,b,c,mat1,arr1,arr2);
	if(x==0)
	{
		printf("element not found");
	}
	else
	{
		for(i=0;i<x;i++)
		{
			printf("element found %d X %d\n",arr1[i],arr2[i]);
		}


	}
}


int Search(int a,int b,int c,int mat1[a][b],int *arr1,int *arr2)
{
	int i,j,count=0;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if(mat1[i][j]==c)
			{
				count++;
				*arr1=i;
				*arr2=j;
				arr1=arr1+1;
				arr2=arr2+1;
			}
		}
	}
	return count;
}

