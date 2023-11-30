//subraction



#define row 3
#define col 3
#include<stdio.h>
int main()
{
	int i,j,mat1[row][col],mat2[row][col];
	printf("enter matrix %d%d\n",row,col);
	printf("enter 1st matrix:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf(" %d",&mat1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("enter 2nd matrix:\n");
		for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf(" %d",&mat2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("givin 1st matrix is:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",mat1[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
	printf("givin 2nd matrix is:\n");
		for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",mat2[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
	printf("adding of two matrix is :\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",mat1[i][j]-mat2[i][j]);
		}
		printf("\n\n");
	}

}

