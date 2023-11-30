//1.Write a system program to implement your own shell?


#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


int mysystem(char *);
int main()
{
    int status,ret;
    pid_t pid;
    char buff[100];
    while(1)
    {
	printf("$ ");
	scanf("%99[^\n]s",buff);
	getchar();
	pid=fork();
	if(pid<0)
	{
	    perror("fork fail");
	    exit(1);
	}
	else if (strcmp(buff, "exit") == 0)
	{
	    break;
	}
	else if(pid==0)
	{
	    ret=execl("/bin/sh", "sh", "-c", buff, (char *) 0);
	    if(ret == -1)
	    {
		perror("execl fail");
		exit(0);
	    }
	}
	else
	{
	    wait(&status);
	}
    }
	return 0;
}

