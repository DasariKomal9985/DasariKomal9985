#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int count=0;
void *mythread_odd(void *arg){

	printf("number %d is odd\n",count);

	pthread_exit(NULL);
}

void *mythread_even(void *arg){
	while(count<100){
		if(count%2==0)
		{
			printf("number %d is even\n",count);
		}
		else{
			pthread_t odd;
			pthread_create(&odd,NULL,mythread_odd,NULL);
			pthread_join(odd,NULL);
		}
		count++;
	}
	pthread_exit(NULL);
}

int main(){

	pthread_t even,odd;

	pthread_create(&even,NULL,mythread_even,NULL);

	pthread_join(even,NULL);


}

