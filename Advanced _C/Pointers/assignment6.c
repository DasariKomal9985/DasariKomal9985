/*Implement the below functions 

strcpy*/

//string copy
char MyStrcpy(char *str1,char *str2)
{
int i;
for(i=0;*(str2+i)!=0;i++)
{
*(str1+i)=*(str2+i);//coping of frist string to seacond string 
}
return str1;
}

#include<stdio.h>
int MyStrlen(char *str2);
int main()
{
int x;
char str1[10];
char str2[10];
printf("enter string ");
scanf("%s",str1);//enter frist string 
printf("frist string is %s\n",str1);
x=MyStrlen(str1);//finding length of givin string
scanf("%s",str2);//enter seacond string
printf("seacond string is %s\n",str2);
//MyStrcpy(str1,str2,x);//calling function parameters string 1 string 2 and x value
printf("copied frist string to seacond string is %s\n",MyStrcpy(str1,str2));//printing seacond string
}
