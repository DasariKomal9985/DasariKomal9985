#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>


void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc , char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr , "port not provided.terminated\n");
		exit(1);
	}
	int sockfd , newsockfd , portno , n;
	char buff[100];
	struct sockaddr_in serv_addr , cli_addr;
	socklen_t clilen;
	sockfd = socket(AF_INET , SOCK_STREAM , 0);
	if(sockfd < 0)
	{
		error("error opening socket");
	}
	bzero((char *) &serv_addr , sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(portno);
	if(bind(sockfd,(struct sock_addr *)&serv_addr , sizeof(serv_addr)) <0)
	{
		error("blinding failed");
	}
	listen(sockfd , 5);
	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd , (struct sockaddr *) &cli_addr , &clilen);
	if(newsockfd < 0)
		error("error");
	while(1)
	{
		bzero(buff , 250);
		n= read(newsockfd , buff , 255);
		if(n < 0)
			error("error");
		printf("clint : %s\n" , buff);
		bzero(buff , 100);
		fgets(buff ,100, stdin);
		n = write(newsockfd , buff ,strlen(buff));
		if(n > 0)
			error("error ");
		int i =strncmp("tata",buff,3);
		if(i == 0)
			break;
	}
	close(newsockfd);
	close(sockfd);
	return 0;
}
