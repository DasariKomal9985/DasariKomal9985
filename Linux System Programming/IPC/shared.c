#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
int main()
{
void * shared_mem;
char buff[100];
int shmid;
shmid = shmget((key_t)1122,1024,0666 | IPC_CREAT);
printf("key of shared memory is %d\n",shmid);
shared_mem = shmat(shmid,NULL,0);
printf("process attach at %p\n",shared_mem);
printf("enter some data to write to shared memory\n");
read(0,buff,100);
strcpy(shared_mem,buff);
printf("you wrote:%s\n",(char *)shared_mem);
}
