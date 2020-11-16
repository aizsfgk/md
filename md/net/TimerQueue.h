#ifndef MD_NET_TIMERQUEUE_H
#define MD_NET_TIMERQUEUE_H

#include <list>

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>


#include "md/base/UtcTime.h"

namespace md
{
namespace net
{


class Timer;
class TimerId;

class TimerQueue : boost::noncopyable
{
public:
	typedef boost::function<void()> TimerCallback;
	TimerQueue();
	~TimerQueue();

	void tick(UtcTime now);

	TimerId schedule(const TimerCallback &cb, UtcTime at, double interval);
	void cancel(TimerId timerId);

private:
	typedef std::list<Timer*> Timers;
	Timers timers_;
};

}	
}

#endif
