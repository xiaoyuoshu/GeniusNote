#include <string>
#include <netdb.h>
#include <sys/socket.h>

namespace GeniusNote{
	class Client{

		public:
			int init(int port);
			int conn(const std::string& serverIPStr, int serverPort);

			int send(void *buf, size_t size);
			int recv(void *buf, size_t size);
			int stop();

		private:
			int port;
			int sockfd;
			sockaddr_in clientSockAddr;
			sockaddr_in serverSockAddr;

	}
}