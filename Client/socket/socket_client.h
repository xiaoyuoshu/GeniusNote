#ifndef Included_NameModel_H

#define Included_NameModel_H

#include <string>
#include <netdb.h>
#include <sys/socket.h>

namespace GeniusNote{
	class ClientSocket{

		public:
			int init(int port);
			int conn(const std::string& serverIPStr, int serverPort);

			long csend(void *buf, size_t size);
			int crecv(void *buf, size_t size);
			int stop();

		private:
			int port;
			int sockfd;
			sockaddr_in clientSockAddr;
			sockaddr_in serverSockAddr;

	};
}

#endif