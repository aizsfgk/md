#ifndef MD_NET_SOCKET_H
#define MD_NET_SOCKET_H

namespace md
{
namespace net
{

class Socket
{
public:
	explicit Socket(int sockfd) :
		sockfd_(sockfd) {}
	int fd() { return sockfd_; }

	void setTcpNoDelay(bool on);
private:
	int sockfd_;
};


}
}

#endif
