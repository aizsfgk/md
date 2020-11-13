#ifndef MD_BASE_UTCTIME_H
#define MD_BASE_UTCTIME_H

#include <md/base/Types.h>

class UtcTime
{
public:
	UtcTime();

	explicit UtcTime(int64_t microSecondsSinceEpoch);

	string toString() const;

	bool valid() const { return microSecondsSinceEpoch_ > 0; }

	bool before(UtcTime rhs) const
	{
		return microSecondsSinceEpoch_ < rhs.microSecondsSinceEpoch_;
	}

	bool after(UtcTime rhs) const
	{
		return microSecondsSinceEpoch_ > rhs.microSecondsSinceEpoch_;
	}

	bool equals(UtcTime rhs) const
	{
		return microSecondsSinceEpoch_ == rhs.microSecondsSinceEpoch_;
	}

	int64_t microSecondsSinceEpoch() const { return microSecondsSinceEpoch_; }

	static UtcTime now();
	static const int kMicroSecondsPerSecond = 1000 * 1000;


private:
	int64_t microSecondsSinceEpoch_;
};

inline bool operator<(UtcTime lhs, UtcTime rhs)
{
	return lhs.before(rhs);
}

inline bool operator==(UtcTime lhs, UtcTime rhs)
{
	return lhs.equals(rhs);
}

inline double timeDifference(UtcTime high, UtcTime low)
{
	int64_t diff = high.microSecondsSinceEpoch() - low.microSecondsSinceEpoch();
	return static_cast<double>(diff) / UtcTime::kMicroSecondsPerSecond;
}

#endif
