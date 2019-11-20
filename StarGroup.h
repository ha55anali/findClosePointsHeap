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

	void changeDis(float n) {
		distance = n;
	}

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

	friend ostream& operator<<(ostream& os, groupPair const& g) {
		cout << "star1: " << g.star1;
		cout << "  star2: " << g.star2;
		cout << "  distance: " << g.distance;

		return os;
	}
};

class starGroup {
public:
	starGroup(string filename);

	void getGroups();

	void print();

private:
	vector< vector<int> > groupPos;
	myHeap<groupPair>* starHeap;
	vector< list<int> > groupList;
	vector<star>* starList;
	int groups;
	int starCount;

	//updates the matrix positions according to the linked list
	void updateMatrix();

	int getCurrentGroupCount();

	//verifies the string only contains numbers, spaces, 2 or less '.' or '#' 
	bool checkNumericalSymbol(string lot);
	//verifies if the string contains at least one space
	bool checkSpace(string lot);
	void validateFile(string filePath);
	//reads data from file and stores it in a vector
	void readFile(string FilePath);

};