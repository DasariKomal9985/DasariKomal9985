#include<stdio.h>
int avilablestock();
int purchase();
int sell();
int stock=500;
int main()
{
	int n;
	while(1)
	{
		printf("1. check avalible stock\n2. purchase\n3. sell\n4. quit\n");
		scanf("%d",&n);
		if(n==1)
		{
			avilablestock();
		}
		else if(n==2)
		{
			purchase();
		}
		else if(n==3)
		{
			sell();
		}
		else if(n==4)
		{
			break;
		}

	}
}
	
