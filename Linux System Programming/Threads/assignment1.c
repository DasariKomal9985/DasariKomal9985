#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *mythread_even(void *);
void *mythread_odd(void *);
int count=0;
int main()
{
	pthread_t even , odd;
	pthread_create(&even,NULL,mythread_even,NULL);
	pthread_join(even,NULL);
}

void *mythread_even(void *arg)
{
	while(count<100)
	{
		if(count%2==0)
		{
			printf("%d\n",count);
		}
		else
		{
			pthread_t odd;
			pthread_create(&odd,NULL,mythread_odd,NULL);
			pthread_join(odd,NULL);
		}
		count++;
	}
	pthread_exit(NULL);
}

void *mythread_odd(void *arg)
{
	printf("%d\n",count);
	pthread_exit(NULL);
}
