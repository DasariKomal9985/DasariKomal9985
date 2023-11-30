#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
int main()
{
void * shared_mem;
char buff[100];
int shmid;
memset(buffer, '\0', sizeof(buffer));
shmid = shmget((key_t)1122,1024,0666);
printf("key of shared mem is %d\n",shmid);
shared_mem = shmat(shmid,NULL,0);
printf("process attached at %p\n",shared_mem);
printf("data read from shared memory is :%s\n",(char *)shared_mem);
}

