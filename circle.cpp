#include "circle.h"
#include <cmath>


circle::circle(float r, float x, float y)
{
	radius = r;
	x_center = x;
	y_center = y;
}

circle::circle() {
	radius = 0;
	x_center = 0;
	y_center = 0;
}

void circle::set_circle(float r, float x, float y)
{
	this->radius = r;
	this->x_center = x;
	this->y_center = y;
}

float circle::sqaure(float a, float b, float c)
{
	float p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}


bool circle::triangle_around(float a, float b, float c)
{
	if ((a + b > c) && (b + c > a) && (a + c > b)) {
		float p = (a + b + c) / 2;
		float rradius = sqrt(((p - a) * (p - b) * (p - c)) / p);

		if (radius == rradius) return true;
		else return false;
	}
	else return false;
}


bool circle::triangle_in(float a, float b, float c)
{
	if ((a + b > c) && (b + c > a) && (a + c > b)) {
		float s = sqaure(a, b, c);
		float calc_r = (a * b * c) / (4 * s);

		if (calc_r <= this->radius) return true;
		else return false;
	}
	else return false;
}


bool circle::check_circle(float x_cntr, float y_cntr)
{
	float dist = sqrt(pow(x_cntr - this->x_center, 2) + pow(y_cntr - this->y_center, 2));
	if (dist <= this->radius) return true;
	else return false;
}