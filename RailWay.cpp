#include "RailWay.h"

RailWay::RailWay()
{
	ifstream fout;
	fout.open("DB.txt");
	string tempDestination;
	size_t tempHour;
	size_t tempMin;
	if (fout.is_open()) {
		while (!fout.eof()) {
			fout >> tempDestination;
			fout >> tempHour;
			fout >> tempMin;
			if (tempDestination != "") {
				Time t(tempHour, tempMin);
				Train tempObj(tempDestination, t);
				railWay.push_back(tempObj);
			}
		}
	}

}

RailWay::~RailWay()
{
	ofstream out;
	out.open("DateBase.txt");
	if (out.is_open())
	{
		for (auto& v : railWay)
		{
			out << v.getDestinationPlace() << endl;
			out << v.getArriveTime().getHour() << endl;
			out << v.getArriveTime().getMin() << endl;


		}
	}

}

void RailWay::addTrain(const Train& obj)
{
	railWay.push_back(obj);

}

void RailWay::printSomeTrain(const size_t& index) const
{
	if (index <= railWay.size())
		cout << *(railWay.begin() + index) << endl;
}

void RailWay::getsOnTrain(const size_t& index)
{
	if (index <= railWay.size())
		railWay.erase(railWay.begin() + index);
}

void RailWay::editTrain(const int& index, const string& destinationPlace, const Time& arriveTime)
{
	if (index >= 0) {
		if (destinationPlace == "") {
			(*(railWay.begin() + index)).setArriveTime(arriveTime);
		}
		else if (arriveTime == Time()) {
			(*(railWay.begin() + index)).setDestinationPlace(destinationPlace);
		}
		else if (arriveTime == Time() && destinationPlace == "") {
			(*(railWay.begin() + index)).setDestinationPlace(destinationPlace);
			(*(railWay.begin() + index)).setArriveTime(arriveTime);

		}
	}
}



ostream& operator<<(ostream& os, const RailWay& obj)
{

	for (auto& v : obj.railWay) {
		os << "##############" << endl;
		os << v << endl;
	}
	return os;
}