#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<sys/shm.h>

	char * buffer[100];
int main()
{
	int data_processed;
	void * shared_mem;
	pid_t pid;
	int shmid;



	pid_t fork_result;

	memset(buffer, '\0', sizeof(buffer));


	shmid = shmget((key_t)1122,1024,0666 | IPC_CREAT);

	pid = fork();
	if(pid == 0)
	{
		printf("enter some data to write to shared memory\n");
		read(0,buffer,100);
		strcpy(shared_mem,*buffer);

	}

	else
	{
		sprintf(*buffer, "%d", shmid);
		(void)execl("sharedrec", "sharedrec", *buffer, (char *)0);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

