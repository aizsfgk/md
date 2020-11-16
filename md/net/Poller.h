#ifndef MD_NET_POLLER_H
#define MD_NET_POLLER_H

#include <boost/noncopyable.hpp>

namespace md
{
namespace net
{

//
// Base class for IO Multiplexing
// 
class Poller : boost::noncopyable
{
public:
	virtual ~Poller();                       // 西沟函数
	virtual void poll(int timeoutMs) = 0;    // 核心函数

	static Poller *newDefaultPoller();       // 新建默认Poller
};

} // namespace net
} // namespace md

#endif
