#pragma once

class circle {
private:
	float radius;
	float x_center;
	float y_center;
public:
	circle(float r, float x, float y);
	circle();
	void set_circle(float r, float x, float y);
	float sqaure(float a, float b, float c);
	bool triangle_around(float a, float b, float c);
	bool triangle_in(float a, float b, float c);
	bool check_circle(float x_cntr, float y_cntr);
};