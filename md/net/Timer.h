#ifndef MD_NET_TIMER_H
#define MD_NET_TIMER_H

#include <map>
#include <boost/noncopyable.hpp>
#include <boost/function.hpp>

#include "md/base/UtcTime.h"


namespace md
{
namespace net
{

class Timer : boost::noncopyable
{
public:
	typedef boost::function<void()> TimerCallback;

	Timer(const TimerCallback &cb, UtcTime at, double interval)
		: cb_(cb),
		  expiration_(at),
		  interval_(interval),
		  repeat_(interval > 0.0)
	{
	}

	void run() const
	{
		cb_();
	}

	UtcTime expiration() const { return expiration_; }
	bool repeat() const { return repeat_; }

	void restart(UtcTime now);

private:
	const TimerCallback cb_;          // 回调函数
	UtcTime expiration_;              // 过期时间
	const double interval_;           // 间隔时间
	const bool repeat_;               // 是否重复
};

}	
}

#endif
