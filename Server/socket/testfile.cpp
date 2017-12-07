#include "server_socket.h"
#include <iostream>
//#include "../log/log.h"
char buf[50];
using namespace GeniusNote;

int main(int argc,char* argv[]){
	ServerSocket server;

	int sockfd = server.init(1234);
	int start = server.startServer();
	int acc = server.acceptCon();

	long recvSize = server.recvNote(acc,(void*) buf,50);

	printf("%s\n",buf);

	int send = server.sendNote(acc,(void*) buf,50);

	server.CloseServer(acc);
}