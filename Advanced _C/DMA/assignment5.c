// Implement itoa function and return the string from the function. Print the result in main. itoa function takes an integer as input, and stores the integer in a string


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mystrrev(char *str)
{
	int j,k,temp;

	k=strlen(str);

	for(int i=0,j=k-1;i<j;i++,j--)
	{
		temp=*(str+i);
		*(str+i)=*(str+j);
		*(str+j)=temp;
	}
}

char *myitoa(int num)
{
	char *s=(char *)malloc(10*sizeof(char));
	int i=0;

	while(num!=0)
	{
		s[i++]=num%10+48;
		num/=10;
	}
	s[i]='\0';
	mystrrev(s);
	return s;
}

int main()
{
	int *n;
	n=(int *)malloc(sizeof(int));
	printf("Enter integer number\n");
	scanf("%d",&n);
	char *s=(char *)malloc(10*sizeof(char));
	s=myitoa(n);
	printf("%s\n",s);

	return 0;
}
