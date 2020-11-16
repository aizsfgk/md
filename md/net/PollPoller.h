#ifndef MD_NET_POLLPOLLER_H
#define MD_NET_POLLPOLLER_H

#include "md/net/Poller.h"

#include <poll.h>
#include <vector>

namespace md
{
namespace net
{

class PollPoller : public Poller
{
public:
	virtual ~PollPoller();
	virtual void poll(int timeoutMs);
private:
	typedef std::vector<struct pollfd> PollFdList;
	PollFdList pollfds_;
};

} // namespace net
} // namespace md


#endif
