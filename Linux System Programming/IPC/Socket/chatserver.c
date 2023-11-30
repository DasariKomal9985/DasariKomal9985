#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

void *thread_write(void *arg);
void *thread_read(void *arg);

int server_sockfd, client_sockfd;
int server_len, client_len;
struct sockaddr_un server_address;
struct sockaddr_un client_address;

void fun(int sig)
{
	unlink("abc_socket");
	exit(0);
}


int main()
{
	pthread_t a,b;
	void *retval;
	int ret;
	signal(SIGINT,fun);
	unlink("abc_socket");
	server_sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);


	server_address.sun_family = AF_UNIX;
	strcpy(server_address.sun_path, "abc_socket");
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

	listen(server_sockfd, 5);
	client_len = sizeof(client_address);
	client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address, &client_len);

	ret=pthread_create(&a,NULL,thread_read,NULL);
	if(ret<0)
	{
		perror("Thread a create fail\n");
		exit(1);
	}

	ret=pthread_create(&b,NULL,thread_write,NULL);
	if(ret<0)
	{
		perror("Thread a create fail\n");
		exit(1);
	}
	ret=pthread_join(a,&retval);
	if(ret<0)
	{
		perror("Thread fail\n");
	}
	ret=pthread_join(b,&retval);
	if(ret<0)
	{
		perror("Thread fail\n");
	}
}


void *thread_read(void *arg)
{
	int ret;
	char buff[100];
	while(1)
	{
		ret = read(client_sockfd, buff, 100);
	if(ret == 0)
	{
		break;
	}
		printf("chat form client = %s\n",buff);
		memset(buff, '\0', sizeof(buff));

	}
}


void *thread_write(void *arg)
{
	char buff1[100];
	while(1)
	{
		read(0,buff1,100);
		write(client_sockfd,buff1,100);
		memset(buff1, '\0', sizeof(buff1));
	}
}
