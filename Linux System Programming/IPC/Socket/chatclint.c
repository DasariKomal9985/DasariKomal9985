#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
void *thread_write(void *);
void *thread_read(void *);
int sockfd;
int len,ret;
pthread_t a,b;
struct sockaddr_un address;
int result;
void *retval;

int main()
{
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, "abc_socket");
	len = sizeof(address);
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if(result == -1)
	{
		perror("oops: client1");
		exit(1);
	}

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
		ret = read(sockfd, buff,100);
		if(ret == 0)
		{
		break;
		}
		printf("char from server = %s\n",buff);
		memset(buff, '\0', sizeof(buff));
	}
}

void *thread_write(void *arg)
{
	char buff[100];
	while(1)
	{
		read(0,buff,100);
		write(sockfd,buff,100);
		memset(buff, '\0', sizeof(buff));
	}
}
