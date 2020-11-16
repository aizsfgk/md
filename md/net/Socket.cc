#include "md/net/Socket.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>


using namespace md;
using namespace md::net;

void Socket::setTcpNoDelay(bool on)
{
	int optVal;
	optVal = on ? 1 : 0;
	::setsockopt(sockfd_, IPPROTO_TCP, TCP_NODELAY,
		 &optVal, sizeof(optVal));
}
