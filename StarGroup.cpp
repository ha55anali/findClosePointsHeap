#include "StarGroup.h"

#include "star.h"
starGroup::starGroup(string filename) {
	readFile(filename);

	//create group list
	groupList.resize(starCount);
	for (int c = 0; c < starCount; ++c) {
		groupList[c].push_back(c);
	}

	//create heap
	starHeap = new myHeap<groupPair>(starCount * (starCount - 1) / 2);
	for (int c = 0; c < starCount; ++c) {

		for (int x = c + 1; x < starCount; ++x) {
			starHeap->insert( groupPair( c,x,getDistance(starList->at(c),starList->at(x)) ) );
		}
	}

	groupPos.resize(starCount);
	for (int c = 0; c < starCount; ++c)
		groupPos[c].resize(starCount);

	updateMatrix();
}

void starGroup::updateMatrix()
{
	for (int c = 0; c < starHeap->getSize(); ++c) {
		groupPair temp = (*starHeap)[c];
		groupPos[temp.star2][temp.star1] = c;
		groupPos[temp.star1][temp.star2] = c;
	}
}


bool starGroup::checkNumericalSymbol(string lot) {
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

bool starGroup::checkSpace(string lot) {
	bool space = 0;
	for (auto i = lot.begin(); i != lot.end(); ++i) {
		if (*i == ' ' && i + 1 != lot.end())
			space = 1;
	}

	return space;
}

void starGroup::validateFile(string filePath) {
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

void starGroup::readFile(string FilePath) {
	validateFile(FilePath);
	ifstream file(FilePath);

	char dummy;

	file >>starCount;
	file >> dummy; //read '#' from file
	file >> groups;

	starList = new vector<star>;
	starList->reserve(starCount);

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

}
