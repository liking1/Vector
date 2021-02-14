#pragma once
#include <algorithm>
#include <fstream>
#include "Train.h"

using namespace std;
class RailWay
{
public:
	RailWay();
	void addTrain(const Train& obj);
	void printSomeTrain(const size_t& index) const;
	void getsOnTrain(const size_t& index);
	void editTrain(const int& index = -1, const string& destinationPlace = "", const Time& arriveTime = Time());
	friend ostream& operator<<(ostream& os, const RailWay& obj);
	~RailWay();
private:
	vector<Train> railWay;
};