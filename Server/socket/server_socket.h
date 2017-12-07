#ifndef Included_NameModel_H

#define Included_NameModel_H

#include <string>
#include <netdb.h>
#include <sys/socket.h>

namespace GeniusNote{
	class ServerSocket
	{
		public:
			int init(int port);
			int startServer();
			int acceptCon();

			int sendNote(int sockfd,void* buf,size_t size);
			long recvNote(int sockfd,void* buf,size_t size);

			int CloseServer(int clnt_sock);

		private:
			int port;
			int sockfd;
			sockaddr_in serverAddr;
	};
}

#endif