/*Declare a two-dimensional array of elements for sales details of a store, for each item, for each sales man. Take the sales values as input and print the array in matrix form.
Find out and print the following :
1 ) Total sales by each sales man
2 ) Total sales for a item
3 ) Total sales*/


#include<stdio.h>
int main()
{
	int a,b,i,j,col,row,sum;
	printf("Enter no of salesman:\n");
	scanf("%d",&a);
	printf("Enter no of product :\n");
	scanf("%d",&b);
	row=b;
	col=a;
	int mat1[row][col];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("enter quantity of product %d sold by sales man %d:  ",i+1,j+1);
			scanf("%d",&mat1[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",mat1[i][j]);
		}
		printf("\n");
	}
	printf("every sales man is:\n");
	for(i=0;i<col;i++)
	{
		for(sum=0,j=0;j<row;j++)
		{
			sum=sum+mat1[i][j];
		}
		printf("sales man is %d and value is %d\n",i,sum);
	}
	printf("\n\n");
	printf("every product is :\n");
	for(i=0;i<col;i++)
	{
		for(sum=0,j=0;j<row;j++)
		{
			sum=sum+mat1[j][i];
		}
		printf("product is %d\n",sum);
	}
	printf("\n\n");
	printf("total sales is ");
	for(sum=0,i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			sum=sum+mat1[i][j];
		}
	}
	printf("total is %d",sum);
}
