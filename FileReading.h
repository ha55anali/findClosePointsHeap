#pragma once
#include "star.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//verifies the string only contains numbers, spaces, 2 or less '.' or '#' 
bool checkNumericalSymbol(string lot) {
	int periodCount = 0;
	for (auto i = lot.begin(); i != lot.end(); ++i) {
		bool numericSymbol = 0;
		if (*i >= '0' && *i <= '9')
			numericSymbol = 1;
		if (*i == '#' || *i == '.' || *i == ' ')
			numericSymbol = 1;

		if (*i == '.')
			++periodCount;

		if (numericSymbol == 0)
			return 0;
	}
	if (periodCount <= 2)
		return 1;

	return 0;
}

//verifies if the string contains at least one space
bool checkSpace(string lot) {
	bool space = 0;
	for (auto i = lot.begin(); i != lot.end(); ++i) {
		if (*i == ' ' && i + 1 != lot.end())
			space = 1;
	}

	return space;
}

void validateFile(string filePath) {
	ifstream file(filePath);

	int starCount;
	file >> starCount;

	string lot;
	int LineCount = 0;
	while (getline(file, lot)) {

		if (!lot.empty()) {
			++LineCount;

			if (checkNumericalSymbol(lot) == 0)
				throw invalid_argument("Input File is corrupt");
			if (checkSpace(lot) == 0)
				throw invalid_argument("Input File is corrupt");
		}
	}

	if (starCount != LineCount - 1)
		throw invalid_argument("Input File is corrupt");
}

//reads data from file and stores it in a vector
vector<star>* readFile(string FilePath, int& groups) {
	validateFile(FilePath);
	ifstream file(FilePath);

	int StarCount;
	char dummy;

	file >> StarCount;
	file >> dummy; //read '#' from file
	file >> groups;

	vector<star>* starList = new vector<star>;
	starList->reserve(StarCount);

	int count = 0;

	while (!file.eof()) {
		float x_cord;
		float y_cord;
		file >> x_cord;
		file >> y_cord;

		star s1(count, x_cord, y_cord);

		starList->push_back(s1);

		++count;
	}

	return starList;
}
