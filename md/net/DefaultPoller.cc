#include "md/net/Poller.cc"
#include "md/net/PollPoller.cc"

Poller *Poller::newDefaultPoller()
{
	return new PollPoller;
}