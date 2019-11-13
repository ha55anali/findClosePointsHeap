#pragma once

#include "star.h"

class starPair {
	starPair(star*,star*);

	bool operator==(starPair const& s2);
	bool operator<(starPair const& s2);
	bool operator>(starPair const& s2);

private:
	star * star1;
	star * star2;

	int distance;
};

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
