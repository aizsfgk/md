#include "md/net/TimerQueue.h"

#include "md/net/Timer.h"
#include "md/net/TimerId.h"

using namespace md;
using namespace md::net;

TimerQueue::TimerQueue()
{
}

TimerQueue::~TimerQueue()
{

}

void TimerQueue::tick(UtcTime now)
{

}

TimerId TimerQueue::schedule(const TimerCallback &cb, UtcTime at, double interval)
{
	Timer* timer = new Timer(cb, at, interval);
	timers_.push_front(timer);
	return TimerId(timer);
}