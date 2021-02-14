#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Time.h"

using namespace std;
class Train
{
public:
	Train(string destinationPlace, Time& arriveTime);
	bool canSet(const string& destinationPlace, const Time& arriveTime);
	void setDestinationPlace(const string& destinationPlace);
	void setArriveTime(const Time& arriveTime);
	friend ostream& operator<<(ostream& os, const Train& obj);
	friend bool& operator<(const Train& objFirst, const Train& objSecond);
	string getDestinationPlace() const;
	Time getArriveTime() const;

private:
	string destinationPlace;
	Time arriveTime;
	static size_t countTrain;
	size_t number;
	static vector<string> placeName;
	static vector<Time> timeArrivePlace;
};