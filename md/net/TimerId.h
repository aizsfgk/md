#ifndef MD_NET_TIMERID_H
#define MD_NET_TIMERID_H

namespace md
{
namespace net
{

class Timer;

class TimerId
{
public:
	explicit TimerId(Timer *value)
		: value_(value) { }

private:
	Timer *value_;
};

}
}

#endif
