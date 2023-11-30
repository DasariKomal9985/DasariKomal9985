// Write two source files, main.c and swap.c. The main function initializes a two-element array of ints, and then calls the swap function to swap the pair.



void fun(int *arr)//bringing address of arr (value:10,20)
{
	int temp;
	temp=*(arr+0);//temporary value =adders of the arr+0 1st element
	*(arr+0)=*(arr+1);//arr of seadond element to the 1 element
	*(arr+1)=temp;//temp value to the 1st array
}






#include<stdio.h>
void fun(int *arr);
int main()
{
	int i;
	int arr[2]={10,20};//array of 1st element and 2nd one
	printf("givin elements is ");
	for(i=0;i<2;i++)
	{
		printf("%d\n",*(arr+i));//printing givin values pointer of arr + index value
	}
	fun(arr);//function calling argument arr is sending
	for(i=0;i<2;i++)
	{
		printf("%d\t",*(arr+i));//after swaping values will be pointer of arr + index value
	}
	return 0;
}
