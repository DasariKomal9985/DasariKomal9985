/* Write a function that communicates with main using a single static variable without taking any input arguments.
Everytime function returns something using the static variable,after using it, main sends another input using the same variable and calls the function again.
eg., print the square of each number of an array :
for each number of the array :
    call the function
    main gets the static variable address as return value from function.
    main puts the array element in static variable.
in the function :
    create static variable.
    if static variable value is not zero, print its square.
    function sends static variable address back to main.*/





#include<stdio.h>
static int x;
int * square();
int main()
{
	int arr[10],i,*res;
	printf("enter 10 elements\n");
	for(i=0;i<10;i++)
		scanf("%d",arr+i);
	for(i=0;i<10;i++)
	{
		x=*(arr+i);
		res=square();
		printf("square of element %d : %d\n",i,*res);
	}
	return 0;
}


int * square()
{
	int p=1;
	if(x !=0)
		p=x;
	x=p*x;
	return &x;
}

