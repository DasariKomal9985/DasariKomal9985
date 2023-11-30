//2.WAP your own version of system() library?


#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int mysystem(char *);
int main()
{
	printf("start\n");
	mysystem("ls -la");
	printf("end\n");
}
int mysystem(char *command)
{
	int status;
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		execl("/bin/sh", "sh", "-c", command, (char *) 0);
	}
	else
	{
		wait(&status);
	}
}

