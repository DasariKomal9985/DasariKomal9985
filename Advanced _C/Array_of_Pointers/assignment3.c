/* read a date in d-m-y format and print it back in given format below:

eg input :2-3-2000
output: 2nd March, 2000

eg input: 4-1-2001
output: 4th January, 2001 */



#include<stdio.h>
int main()
{
	int d,m,y,dmy;
	printf("enter date of birth dd-mm-yyyy:\n");
	scanf("%d-%d-%d",&d,&m,&y);

	char *str1[4]={"st","nd","rd","th"};
	char *str2[12]={"january","febuary","march","april","may","june","july","augest","september","october","november","december"};
	char *str3[]={};

	if((d<0 || d>31)||(m<1 || m>12)||((d>28)||(m==2)))
	{
		printf("invalid dateformat");
		return 0;
	}
	if(d==1||d==21||d==31)
		dmy=0;
	else if(d==2||d==22)
		dmy=1;
	else if(d==3||d==23)
		dmy=2;
	else
		dmy=3;
	printf("%d%s-%s-%d\n",d,str1[dmy],str2[m-1],y);
}

