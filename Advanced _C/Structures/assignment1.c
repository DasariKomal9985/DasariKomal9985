/* Practice scanf and printf on each member of the structure using a structure variable using the below structure template:

struct student
{
int ID;
char name[50];
int marks[6];
int d,m,y;
float per;
char gender
};

create a structure variable of the above type and read ID , name and marks of 6 subjects, date of birth and date of joining using scanf and printf.
Then calculate the percentage of marks, and store the percentage using per pointer member, and print it.Write a function to calculate the percentage ,and update the percentage member of the structure using function (send only per member using call by reference).*/

#include"assignment1-1.h"
int main()
{
	int i,j,n;
	printf("enter no of students:");
	scanf("%d",&n);
	struct student s[n];
	for(i=0;i<n;i++)
	{
		printf("enter id number of each student:");
		scanf("%d",&s[i].ID);
		printf("enter student each name:%d ",i+1);
		scanf("%s",s[i].name);
		for(j=0;j<6;j++)
		{
			printf("enter evary student marks :%d-",i+1);
			scanf("%d",&s[i].marks[j]);
		}
		printf("enter date of birth of every student:");
		scanf("%d%d%d",&s[i].d1,&s[i].m1,&s[i].y1);
		printf("enter date of joininng of every student:");
		scanf("%d%d%d",&s[i].d2,&s[i].m2,&s[i].y2);
		printf("enter gender of each student :");
		scanf(" %c",&s[i].gender);
	}

printf("id:%d\n studentname:%s\n dob:%d%d%d\n dobjoining:%d%d%d\n gender:%c\n",s[i].ID,s[i].name,s[i].d1,s[i].m1,s[i].y1,s[i].d2,s[i].m2,s[i].y2,s[i].gender);
}

