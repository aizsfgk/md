#include "md/net/Channel.h"

using namespace md;
using namespace md::net;

Channel::Channel(EventLoop *loop, Socket sock)
	: loop_(loop), sock_(sock), events_(0) {}

Channel::~Channel() {}
