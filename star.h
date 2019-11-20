#pragma once

#include <math.h>
#include <iostream>

using namespace std;

class star {
public:
	star(int,float,float);

	int getId() { return id; };

	friend float getDistance(star const& s1,star const& s2);

	friend ostream& operator<<(ostream& os, star const& obj)
	{
		cout << "id: " << obj.id;
		cout << "  xcor: " << obj.x_cord;
		cout << "  ycor " << obj.y_cord;

		return os;
	}
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
	float temp=sqrt(((s1.x_cord- s2.x_cord)*(s1.x_cord - s2.x_cord)) + ((s1.y_cord- s2.y_cord)* (s1.y_cord - s2.y_cord)));
	return temp;
}
