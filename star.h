#pragma once

#include <math.h>

class star {
public:
	star(int,float,float);

	friend float getDistance(star const& s1,star const& s2);
private:
	int id;
	float x_cord;
	float y_cord;
};

star::star(int id,float x_cord,float y_cord)
	:id(id),x_cord(x_cord),y_cord(y_cord)
{

}

float getDistance(star const& s1, star const& s2) {
	return sqrt(pow(s1.x_cord- s2.x_cord, 2) + pow(s1.y_cord- s1.y_cord, 2));
}
