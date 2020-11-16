#ifndef MD_NET_CHANNEL_H
#define MD_NET_CHANNEL_H

#include <boost/noncopyable.hpp>
#include <md/net/Socket.h>

namespace md 
{

namespace net
{
class EventLoop;

class Channel : boost::noncopyable
{
public:
	Channel(EventLoop *loop, Socket sock);
	~Channel();

	void handle(int revents);

	EventLoop *getLoop() { return loop_; }

private:
	EventLoop *loop_;
	Socket sock_;
	int events_;
};

}	// end namespace net
}   // end namespace md

#endif
