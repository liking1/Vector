#include "Time.h"

Time::Time(const size_t& hour, const size_t& min)
{
	setHour(hour);
	setMin(min);
}

Time::Time(const Time& time)
{
	this->hour = time.hour;
	this->min = time.min;
}

void Time::setTime(const size_t& hour, const size_t& min)
{
	setHour(hour);
	setMin(min);
}

void Time::setMin(const size_t& min)
{
	if (min <= 60 && min > 0)
		this->min = min;
	else
		this->min = 00;
}

void Time::setHour(const size_t& hour)
{
	if (hour >= 0 && hour < 24)
		this->hour = hour;
	else
		this->hour = 00;
}

size_t Time::getMin() const
{
	return min;
}

size_t Time::getHour() const
{
	return hour;
}

void Time::operator=(const Time& obj)
{
	this->hour = obj.hour;
	this->min = obj.min;
}

bool& operator==(const Time& objFirst, const Time& objSecond)
{
	bool isTrue = (objFirst.hour == objSecond.hour && objSecond.min == objFirst.min);
	return isTrue;
}

ostream& operator<<(ostream& ost, const Time& tr)
{
	if (tr.hour == 0)
		if (tr.min == 0) {
			ost << "Time 00:00" << endl;
			return ost;
		}
		else {
			if (tr.min < 10) {
				ost << "Time 00:0" << tr.min << endl;
				return ost;
			}
			else {
				ost << "Time 00:" << tr.min << endl;
				return ost;
			}

		}
	if (tr.min < 10) {
		if (tr.hour > 10) {
			ost << tr.hour << ":0" << tr.min << endl;
			return ost;
		}
		else {
			ost << "0" << tr.hour << ":0" << tr.min << endl;
		}
	}
	else {
		if (tr.hour > 10) {
			ost << tr.hour << ":" << tr.min << endl;
			return ost;
		}
		else {
			ost << "0" << tr.hour << ":" << tr.min << endl;
		}
	}
}

bool operator<(const Time& first, const Time& second)
{
	if (first.hour < second.hour) {
		return false;
	}
	else {
		if (first.min < second.min) {
			return false;
		}
	}
	return true;
}