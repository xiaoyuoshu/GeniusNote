#include "socket_client.h"
#include <iostream>
//#include "../log/log.h"
char buf[50];
using namespace GeniusNote;

int main(int argc,char* argv[]){
	ClientSocket client;
	int sockfd = client.init(2334);
	int con = client.conn("127.0.0.1",2333);

	fgets(buf,50,stdin);

	long ssize = client.csend((void*)buf,50);
	int rsize = client.crecv((void*) buf,50);

	printf("%s\n", buf );
	int st = client.stop();
}