#pragma once
#include <iostream>

using namespace std;
class Time
{
public:
	Time() = default;
	Time(const size_t& hour, const size_t& min);
	Time(const Time& obj);

	void setTime(const size_t& hour, const size_t& min);
	void setMin(const size_t& min);
	void setHour(const size_t& hour);
	size_t getMin() const;
	size_t getHour() const;

	void  operator=(const Time& obj);
	friend bool& operator==(const Time& objFirst, const Time& objSecond);
	friend ostream& operator<<(ostream& os, const Time& obj);
	friend bool operator<(const Time& objFirst, const Time& objSecond);
private:
	size_t min;
	size_t hour;
};