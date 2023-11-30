// What is a zombie process? What is an orphan process? WAP to create a zombie process?

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
	pid_t pid;
	char *msg;
	int n;
	printf("fork starting\n");
	pid = fork();
	switch(pid)
	{
		case -1:perror("fork failed");
			exit(1);
		case 0:
			n=3;
			msg="this is child";
			break;
		default:
			n=5;
				msg="this is parent";
			break;
	}
	for(;n>0;n--)
	{
		printf("%s\n",msg);
		sleep(1);
	}
}

