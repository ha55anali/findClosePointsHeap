#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>

#include "heap.h"

class star;

struct groupPair {
	float distance;
	int star1;
	int star2;

	groupPair(int s1, int s2,float di)
		:star1(s1), star2(s2), distance(di)
	{};

	groupPair() {};

	bool operator==(groupPair const& obj) {
		if (distance == obj.distance)
			return 1;
		return 0;
	}
	bool operator<(groupPair const& obj) {
		if (distance < obj.distance)
			return 1;
		return 0;
	}
	bool operator>(groupPair const& obj) {
		if (distance > obj.distance)
			return 1;
		return 0;
	}
};

class starGroup {
public:
	starGroup(string filename);

private:
	myHeap<groupPair>* starHeap;
	vector< list<int> > groupList;
	vector<star>* starList;
	int groups;
	int starCount;

	//verifies the string only contains numbers, spaces, 2 or less '.' or '#' 
	bool checkNumericalSymbol(string lot);
	//verifies if the string contains at least one space
	bool checkSpace(string lot);
	void validateFile(string filePath);
	//reads data from file and stores it in a vector
	void readFile(string FilePath);

};