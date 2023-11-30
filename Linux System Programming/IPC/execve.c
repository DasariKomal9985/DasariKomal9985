#include<stdio.h>
#include<unistd.h>
int main()
{
printf("i am in exec demo.c\n");
printf("pid of exec demo.c is %d\n",getpid());
char * argv[] = {"./hello",NULL};
char *const envp[5]="hello";
execle(argv[0],"argv",NULL,envp[0]);
printf("comming back to execv_demo.c\n");
return 0;
}
