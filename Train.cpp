#include "Train.h"

size_t Train::countTrain = 0;
vector<string> Train::placeName;
vector<Time> Train::timeArrivePlace;

Train::Train(string destinationPlace, Time& arriveTime)
{
	if (canSet(destinationPlace, arriveTime)) {
		setDestinationPlace(destinationPlace);
		setArriveTime(arriveTime);
		placeName.push_back(destinationPlace);
		timeArrivePlace.push_back(arriveTime);
		++countTrain;
		number = countTrain;
	}
}

bool Train::canSet(const string& place, const Time& arriveTime)
{
	size_t i = 0;
	for (auto& v : placeName) {
		if (v == destinationPlace) {
			if (*(timeArrivePlace.begin() + i) == arriveTime) {
				return false;
			}
		}
		++i;
	}
	return true;
}

void Train::setDestinationPlace(const string& destinationPlace)
{
	if (!destinationPlace.empty())
		this->destinationPlace = destinationPlace;
}

void Train::setArriveTime(const Time& arriveTime)
{
	this->arriveTime = arriveTime;
}

string Train::getDestinationPlace() const
{
	return destinationPlace;
}

Time Train::getArriveTime() const
{
	return arriveTime;
}

ostream& operator<<(ostream& os, const Train& obj)
{
	os << "Number train : " << obj.number << endl;
	os << "Destination place : " << obj.destinationPlace << endl;
	os << "Arrive time : " << obj.arriveTime;
	return os;
}

bool& operator<(const Train& objFirst, const Train& objSecond)
{
	bool isTrue = objFirst.arriveTime < objSecond.arriveTime;
	return isTrue;
}