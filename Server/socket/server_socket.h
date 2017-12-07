#include <string>
#include <netdb.h>
#include <sys/socket.h>

namespace GeniusNote{
	class Server
	{
		public:
			int init(int port);
			int startServer();
			int acceptCon();

			int sendNote();
			long recvNote();

			int CloseServer();

		private:
			int port;
			int sockfd;
			sockaddr_in serverAddr;
	};
}