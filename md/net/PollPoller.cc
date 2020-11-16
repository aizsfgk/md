#include "md/net/PollPoller.h"

#include <poll.h>

using namespace md;
using namespace md::net;

PollPoller::~PollPoller()
{

}

void PollPoller::poll(int timeoutMs)
{
	// make a copy
	PollFdList pollfds(pollfds_);
	
	int numEvents = ::poll(&*pollfds.begin(), pollfds.size(), timeoutMs);

	for (PollFdList::iterator pfd = pollfds.begin();
		pfd != pollfds.end() && numEvents > 0; ++pfd)
	{
		if (pfd->revents > 0)
		{
			--numEvents;
		}
	}
}