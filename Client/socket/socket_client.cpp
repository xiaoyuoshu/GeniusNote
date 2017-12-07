#include <cstdio>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <cstring>
#include <iostream>

#include "socket_client.h"
//#include "../log/log.h"

namespace GeniusNote{
		int ClientSocket::init(int port){
		in_addr_t clientIP = inet_addr("127.0.0.1");

		int sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if(sockfd==-1){
			printf("create socket fault\n");
		}else{
			printf("create socket success\n");
		}

		sockaddr_in clientSockAddr;
  	memset(&clientSockAddr, 0, sizeof(clientSockAddr));

  	clientSockAddr.sin_port = htons(port);
  	clientSockAddr.sin_family = AF_INET;
  	clientSockAddr.sin_addr.s_addr = clientIP;

  	int flag = bind(sockfd, (sockaddr* )&clientSockAddr, sizeof(clientSockAddr));
  	if(flag==-1){
			printf("bind fault\n");
		}else{
			printf("bind success\n");
		}

  	this->port=htons(port);
  	this->sockfd=sockfd;
  	this->clientSockAddr=clientSockAddr;

  	printf("init:%d\n",sockfd);

  	return flag;
	}
	int ClientSocket::conn(const std::string& serverIPStr, int serverPort){
		in_addr_t serverIP = inet_addr(serverIPStr.c_str());

  	sockaddr_in server;
  	memset(&server, 0, sizeof(server));

  	server.sin_addr.s_addr = serverIP;
  	//server.sin_addr.s_addr =inet_addr("107.170.198.120");
  	server.sin_family = AF_INET;
  	server.sin_port = htons(serverPort);

  	printf("conn:%d\n",this->sockfd);

  	int flag = connect(this->sockfd,(const struct sockaddr *)&server,(socklen_t)sizeof(server));
  	if(flag==-1){
			printf("connect fault\n");
		}else{
			printf("connect success\n");
		}

  	this->serverSockAddr = server;

  	return flag;
	}

	long ClientSocket::csend(void *buf, size_t size){
		ssize_t sendSize = send(sockfd, buf, size, 0);
		return sendSize;
	}

	int ClientSocket::crecv(void *buf, size_t size){
		ssize_t recvSize = recv(sockfd, buf, size, 0);
		return recvSize;
	}

	int ClientSocket::stop(){
		close(this->sockfd);
		return 1;
	}
}