#include "socket_client.h"
#include <iostream>
//#include "../log/log.h"
char buf[50];
using namespace GeniusNote;

int main(int argc,char* argv[]){
	ClientSocket client;
	int sockfd = client.init(23334);
	int con = client.conn((const std::string&)"107.170.198.120",23333);

	fgets(buf,50,stdin);

	long ssize = client.csend((void*)buf,50);
	int rsize = client.crecv((void*) buf,50);

	printf("%s\n", buf );
	int st = client.stop();
}