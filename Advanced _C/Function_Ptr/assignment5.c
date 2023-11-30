/* Read an integer and print it back using function pointers for printf and scanf.

printf declaration to use : int printf(char * , ...);
scanf declaration to use : int scanf(char *, ...);

Try it again using alias name and array of function pointers.
*/


#include<stdio.h>
int main()
{
int a;
int (*ptr[])(const char * , ...)={printf,scanf,printf};
ptr[0]("enter any integer\n");
ptr[1]("%d",&a);
ptr[2]("value is :%d\n",a);
return 0;
}
