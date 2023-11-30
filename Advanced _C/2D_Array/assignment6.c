/*	Declare a two dimensional array of characters, read names from the user and print them back with each individual character format (%c) in a loop
 */

#include <stdio.h>
int main()
{
	int i,j,r,c,e,x,count=0;
	printf("enter no.of rows:");
	scanf("%d",&r);
	char a[r][100];
	for(i=0;i<r;i++)
	{
		scanf("%s",a[i]);
	}
	for(i=0;i<r;i++)
	{
		for(j=0;a[i][j]!='\0';j++)
		{
			printf("%c\t",a[i][j]);
		}
		printf("\n");
	}
}
