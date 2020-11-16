#include "md/net/Timer.h"

using namespace md;
using namespace md::net;


void Timer::restart(UtcTime now)
{
	if (repeat_)
	{
		expiration_ = addTime(now, interval_);
	}
	else
	{
		expiration_ = UtcTime::invalid();
	}
}