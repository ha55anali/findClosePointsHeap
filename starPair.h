#pragma once

#include "star.h"

#include <iostream>
using namespace std;

class starPair {
public:
	starPair();
	starPair(star*,star*);

	bool operator==(starPair const& s2);
	bool operator<(starPair const& s2);
	bool operator>(starPair const& s2);

	float retDistance() {
		return distance;
	}

	int retStar1ID() {
		return star1->getId();
	}

	int retStar2ID() {
		return star2->getId();
	}

	friend ostream& operator<<(ostream& os, starPair const& Pair) {
		cout << "id: " << Pair.star1->getId() << " " << Pair.star2->getId() << "  Distance: " << Pair.distance;

		return os;
	}

private:
	star * star1;
	star * star2;

	float distance;
};

starPair::starPair() {
	star1 = nullptr;
	star2 = nullptr;

	distance = 0;
}

starPair::starPair(star* star1,star* star2)
	:star1(star1),star2(star2)
{
	distance = getDistance(*star1, *star2);
}

bool starPair::operator==(starPair const& s2) {
	if (distance == s2.distance)
		return 1;
	return 0;
}

bool starPair::operator<(starPair const& s2) {
	if (distance < s2.distance)
		return 1;
	return 0;
}

bool starPair::operator>(starPair const& s2) {
	if (distance > s2.distance)
		return 1;
	return 0;
}
