#ifndef MD_NET_EVENTLOOP_H
#define MD_NET_EVENTLOOP_H

#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>

#include "md/base/UtcTime.h"
#include "md/net/TimerId.h"

namespace md
{
namespace net
{


class Channel;
class Poller;
class TimerQueue;

class EventLoop : boost::noncopyable
{
public:
	typedef boost::function<void()> TimerCallback; // 定义一个回调函数

	EventLoop();
	~EventLoop();

	// forever
	void loop();   // 循环
	void quit();   // 退出
	void wakeup(); // 唤醒

	// timers
	TimerId runAt(const UtcTime &time,const TimerCallback &cb);
	TimerId runAfter(double delay,const TimerCallback &cb);
	TimerId runEvery(double interval,const TimerCallback &cb);
	void cancel(TimerId timerId);

	void addChannel(Channel *channel);
	void removeChannel(Channel *channel);

private:
	void init(); // 初始化函数
	bool quit_; // atomic
	boost::scoped_ptr<Poller> poller_;          // 轮询器
	boost::scoped_ptr<TimerQueue> timerQueue_;  // 定时器队列
};

}
}

#endif
