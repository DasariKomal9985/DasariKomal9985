//Declare an integer array of size 10 and initialize it to some values. Print the addresses of each element of the array using a pointer. using indirection operator , print the value stored in each element of the array





#include<stdio.h>
int main()
{
	int i;
	int arr[10]={1,2,3,4,5,6,7,8,9,10};		//initlasation of values in array
	int *ptr=&arr[0];				//inilation of frist index value to the pointer 
	for(i=0;i<=10;i++)
	{
		printf("Adders of %d is %p\n",i,ptr);		//storing of adderss
		printf("Value of %d is %d\n",i,*ptr);		//storing of values
		ptr++;						//increment of the pointer
	}
	return 0;
}
