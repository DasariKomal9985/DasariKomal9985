/*Write the following program :
Declare a two dimensional array of elements and find and print its transpose.
eg., if the matrix is :       1 3
                                          4 5
                                          7 8

its transpose should be :     1 4 7
                                                3 5 8*/



#define row 3
#define col 2
#include<stdio.h>
int main()
{
	int i,j,mat1[row][col],mat2[row][col];
	printf("enter matrix %d%d",row,col);
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&mat1[i][j]);
		}
		printf("\n");
	}

	printf("givin matrix of 3*2 is:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",mat1[i][j]);
		}
		printf("\n\n");
	}
	printf("\n");
	printf("its transpose 2*3 is:\n");
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			printf("%d\t",mat1[j][i]=mat1[j][i]);
		}
		printf("\n\n");
	}

}
