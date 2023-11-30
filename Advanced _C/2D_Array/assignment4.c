//	Write a program  for matrix multiplication



#include<stdio.h>
int main()
{
	int i,j,k,sum,row1,col1,row2,col2;
	printf("enter how many rows and col of matrix 1:\n");
	scanf("%d %d",&row1,&col1);
	printf("enter how many rows and col of matrix 2:\n");
	scanf("%d %d",&row2,&col2);
	int mat1[row1][col1],mat2[row2][col2];
	int mat3[row1][col2];
	printf("enter 1st matrix:\n");
	if(col1!=row2)
	printf("enter correct method col1==row2:");
	else
	{
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			scanf(" %d",&mat1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("enter 2nd matrix:\n");
	for(i=0;i<row2;i++)
	{
		for(j=0;j<col2;j++)
		{
			scanf(" %d",&mat2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("givin 1st matrix is:\n");
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			printf("%d\t",mat1[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
	printf("givin 2nd matrix is:\n");
	for(i=0;i<row2;i++)
	{
		for(j=0;j<col2;j++)
		{
			printf("%d\t",mat2[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
	printf("Multiplaction of two matrix is :\n");
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
		{
			mat3[i][j]=0;
			sum=0;
			for(k=0;k<col1;k++)
			{
				sum=sum+mat1[i][k]*mat2[k][j];		
				mat3[i][j]=sum;	
			}

		}
	}
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
		{
			printf("%d\t",mat3[i][j]);
		}
		printf("\n\n");
	}
}
}
