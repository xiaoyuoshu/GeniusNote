#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#include "Socket.h"
#include "../log/log.h"

namespace GeniusNote{
	
	int ServerSocket::init(int port){
		int sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

		struct sockaddr_in serv_addr;
		memset(&serv_addr,0,sizeof(serv_addr));

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
		serv_addr.sin_port = htons(port);

		this->port = htons(1234);
		this->sockfd=sockfd;
		this->serverAddr=serv_addr;

		int flag = bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(sockaddr));

		return serv_sock;
	}

	int ServerSocket::startServer(){
		int flag = listen(this->sockfd,this->port);
		return falg;
	}

	int ServerSocket::acceptCon(int socket){
		struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size =sizeof(clnt_addr);

    int clientfd = accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_addr_size);

    return clientfd;
	}

	int ServerSocket::sendNote(int sockfd,void* buf,size_t size){
    ssize_t sendSize = send(sockfd, buf, size, 0);
    return sendSize;
	}

	long ServerSocket::recvNote(int sockfd,void buf,size_t size){
		ssize_t recvSize = recv(sockfd, buf, size, 0);
		return recvSize;
	}

	int ServerSocket::CloseServer(){

		close(clnt_sock);
    close(serv_sock);

    return 1;
	}
}