# 设置一个环境变量
set(net_SRCS
	Channel.cc
	DefaultPoller.cc
	EventLoop.cc
	Poller.cc
	PollPoller.cc
	Socket.cc
	Timer.cc
	TimerQueue.cc
	)

# 构建一个静态库
add_library(md_net ${net_SRCS})

# 添加子文件夹
add_subdirectory(tests)
