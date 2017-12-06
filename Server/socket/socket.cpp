#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#include "Socket.h"
#include "../log/log.h"

namespace GeniusNote{
	int ServerSocket::init(int port){
		int serv_sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

		struct sockaddr_in serv_addr;
		memset(&serv_addr,0,sizeof(serv_addr));

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
		serv_addr.sin_port = htons(1234);

		bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(sockaddr));

		return serv_sock;
	}

	int ServerSocket::satrtServer(){
		int flag = listen(serv_sock,20);
	}

	int ServerSocket::acceptCon(){
		struct sockaddr_in clnt_addr;
    	socklen_t clnt_addr_size =sizeof(clnt_addr);
    	int clnt_sock=accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_addr_size);
	}

	int ServerSocket::sendNote(){
		char str[]="hello world";
    	write(clnt_sock,str,sizeof(str));
	}

	int ServerSocket::recvNote(){

	}

	int ServerSocket::CloseServer(){
		close(clnt_sock);
    	close(serv_sock);
	}

}