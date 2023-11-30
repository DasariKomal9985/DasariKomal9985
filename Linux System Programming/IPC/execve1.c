#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
pid_t pid;
char * argv[] = {"/bin/ls","-1",NULL};
pid = fork();
if(pid == -1)
return -1;
if(pid == 0)
{
int val = execve(argv[0],argv,NULL);
if(val == -1)
perror("error");
}
else
{
wait(NULL);
printf("done with execve\n");
}
return 0;
}
