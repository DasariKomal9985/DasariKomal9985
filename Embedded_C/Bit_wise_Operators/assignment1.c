//Write a Macro's Set, clear and toggle n'th bit using bit wise operator?

#include<stdio.h>
#define SET_BIT(a,p) a|0x01<<p
#define CLEAR_BIT(a,p) a&(~(0x01<<p))
#define TOGGLE_BIT(a,p) a^(0x01<<p)
#define CHECK_BOX(a,p) a&(0x01<<p)
int main()
{
int a,p;
printf("enter number   :");
scanf("%d",&a);
printf("enter position :");
scanf("%d",&p);
printf("set is       %d\n",SET_BIT(a,p));
printf("clear is     %d\n",CLEAR_BIT(a,p));
printf("toggle is    %d\n",TOGGLE_BIT(a,p));
CHECK_BOX(a,p)?printf("        ON\n"):printf("        OFF\n");
}

