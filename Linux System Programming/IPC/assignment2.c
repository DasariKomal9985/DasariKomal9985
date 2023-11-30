#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/shm.h>

sem_t *prod_lock,*cons_lock;
char *msg;
int a,b,shmid;
pid_t child_pid;

void terminate(int sig)
{
    printf("I got a signal for terminate, for terminate CTRL+C\n");
    sem_unlink("prod");
    sem_unlink("cons");
    exit(0);
}

void main()
{
    signal(SIGINT,terminate);
    prod_lock=sem_open("prod",O_CREAT,0666,1);
    if(prod_lock==NULL)
    {
	perror("semaphore1");
	exit(0);
    }
    cons_lock=sem_open("cons",O_CREAT,0666,0);
    if(cons_lock==NULL)
    {
	perror("semaphore2");
	exit(1);
    }
    sem_getvalue(prod_lock,&a);
    sem_getvalue(cons_lock,&b);
    printf("prod:%d   cons:%d\n",a,b);

    if((shmid=shmget(10,1024,0666|IPC_CREAT))==-1)
    {
	perror("shmget");
	exit(1);
    }
    child_pid = fork();

    if(child_pid==0)
    {
	/*if((shmid=shmget(10,1024,0666))==-1)
	{
	    perror("shmget");
	    exit(1);
	}*/
	msg=shmat(shmid,0,0);

	printf("cmsg:%p\n",msg);

	while(1)
	{
	    sem_wait(cons_lock);
	    printf("Data written in the shared memory is:%s\n",msg);
	    getchar();
	    sem_post(prod_lock);
	}	
    }

    else
    {
	msg=shmat(shmid,0,0);
	printf("pmsg:%p\n",msg);

	while(1)
	{
	    sem_wait(prod_lock);
	    printf("Enter the data you want to write into shared memory\n");
	    fgets(msg,1024,stdin);
	    printf("Data successfully written\n");
	    getchar();
	    sem_post(cons_lock);
	}
    }
}

