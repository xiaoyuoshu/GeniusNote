#include "server_socket.h"

#include <cstdio>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <cstring>

//#include "../log/log.h"

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

		return flag;
	}

	int ServerSocket::startServer(){
		int flag = listen(this->sockfd,this->port);
		if(flag==-1){
			cout<<"listen fault"<<;
		}else{
			cout<<"listen success"<<;
		}

		return flag;
	}

	int ServerSocket::acceptCon(){
		struct sockaddr_in clnt_addr;
    	socklen_t clnt_addr_size =sizeof(clnt_addr);

    	int clientfd = accept(this->sockfd,(struct sockaddr*)&clnt_addr,&clnt_addr_size);
    	if(flag==-1){
			cout<<"accept fault"<<;
		}else{
			cout<<"accept success"<<;
		}

    	return clientfd;
	}

	int ServerSocket::sendNote(int sockfd,void* buf,size_t size){
    	ssize_t sendSize = send(sockfd, buf, size, 0);
    	return sendSize;
	}

	long ServerSocket::recvNote(int sockfd,void* buf,size_t size){
		ssize_t recvSize = recv(sockfd, buf, size, 0);
		return recvSize;
	}

	int ServerSocket::CloseServer(int clnt_sock){

		close(clnt_sock);
    	close(this->sockfd);

    	return 1;
	}
}