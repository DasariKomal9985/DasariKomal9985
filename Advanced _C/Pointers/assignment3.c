 //declare different pointers with different data types. Print the sizes of the pointer variables using sizeof operator. Also print the sizeo    f pointer variables with indirection operators. Observe the results




#include<stdio.h>
int main()
{
	
	int *ptr1;//integer pointer
	short int*ptr2;
	long int*ptr3;
	float *ptr4;//float pointer 
	char *ptr5;//char pointer
	double *ptr6;//double pointer
	long double *ptr7;
	printf("\n\n");
	printf("size of pointer variable:");
	printf("\n\n");
	printf("Size of Integer is           %lu\n",sizeof(ptr1));
	printf("Size of Shortint is          %lu\n",sizeof(ptr2));
	printf("Size of Longint is           %lu\n",sizeof(ptr3));
	printf("Size of Float is             %lu\n",sizeof(ptr4));
	printf("Size of Char is              %lu\n",sizeof(ptr4));
	printf("Size of Double is            %lu\n",sizeof(ptr4));
	printf("Size of longDouble is        %lu\n",sizeof(ptr4));
	printf("\n\n");
	printf("size of pointer variable with indiraction operator:");
	printf("\n\n");
	printf("Size of int is               %lu\n",sizeof(*ptr1));
	printf("Size of shortint is          %lu\n",sizeof(*ptr2));
	printf("Size of longint is           %lu\n",sizeof(*ptr3));
	printf("Size of char is              %lu\n",sizeof(*ptr4));
	printf("Size of float is             %lu\n",sizeof(*ptr5));
	printf("Size of double is            %lu\n",sizeof(*ptr6));
	printf("Size of longdouble is        %lu\n",sizeof(*ptr7));


}

