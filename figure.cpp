#include "figure.h"
#include <iostream>
#include <cmath>
#include <vector>

const double M_PI = 3.14159265358979323846;

figure::figure(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4)
{
	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
	this->x4 = x4;
	this->y1 = y1;
	this->y2 = y2;
	this->y3 = y3;
	this->y4 = y4;

	float AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	float BC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	float CD = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
	float AD = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));

	this->P = AB + BC + CD + AD;
	this->S = 0.5 * abs((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1) - (x2 * y1 + x3 * y2 + x4 * y3 + x1 * y4));
}

void figure::show()
{
	printf("A(x1,y1) = (%.2f,%.2f)\nB(x2,y2) = (%.2f,%.2f)\nC(x3,y3) = (%.2f,%.2f)\nD(x4,y4) = (%.2f,%.2f)\n", x1, y1, x2, y2, x3, y3, x4, y4);
	printf("P = %.2f\nS = %.2f\n", this->P, this->S);
	printf("\n");
}

// Прямоугольник ли фигура
bool figure::is_prug()
{
	float AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	float BC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	float CD = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
	float AD = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));

	float AC = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2)); // d1
	float BD = sqrt(pow(x4 - x2, 2) + pow(y4 - y2, 2)); // d2

	if (AB == CD && BC == AD && AC == BD) return true;
	else return false;
}

// возвращает true, если четырёхугольник можно вписать в окружность и false в противном случае
bool figure::is_in_circle()
{
	std::vector<float> ab(2); ab[0] = x2 - x1; ab[1] = y2 - y1;
	std::vector<float> ba(2); ba[0] = x1 - x2; ba[1] = y1 - y2;
	std::vector<float> bc(2); bc[0] = x3 - x2; bc[1] = y3 - y2;
	std::vector<float> cb(2); cb[0] = x2 - x3; cb[1] = y2 - y3;
	std::vector<float> cd(2); cd[0] = x4 - x3; cd[1] = y4 - y3;
	std::vector<float> dc(2); dc[0] = x3 - x4; dc[1] = y3 - y4;
	std::vector<float> da(2); da[0] = x1 - x4; da[1] = y1 - y4;
	std::vector<float> ad(2); ad[0] = x4 - x1; ad[1] = y4 - y1;

	float cos_abc = (ab[0] * cb[0] + ab[1] * cb[1]) / (sqrt(pow(ab[0], 2) + pow(ab[1], 2)) * sqrt(pow(cb[0], 2) + pow(cb[1], 2)));
	float cos_bcd = (bc[0] * dc[0] + bc[1] * dc[1]) / (sqrt(pow(bc[0], 2) + pow(bc[1], 2)) * sqrt(pow(dc[0], 2) + pow(dc[1], 2)));
	float cos_cda = (cd[0] * ad[0] + cd[1] * ad[1]) / (sqrt(pow(cd[0], 2) + pow(cd[1], 2)) * sqrt(pow(ad[0], 2) + pow(ad[1], 2)));
	float cos_dab = (da[0] * ab[0] + da[1] * ab[1]) / (sqrt(pow(da[0], 2) + pow(da[1], 2)) * sqrt(pow(ab[0], 2) + pow(ab[1], 2)));

	float resA = (180 / M_PI * acos(cos_dab));
	float resB = (180 / M_PI * acos(cos_abc));
	float resC = (180 / M_PI) * acos(cos_bcd);
	float resD = (180 / M_PI) * acos(cos_cda);

	if (resA + resC == 180 && resB + resD == 180) return true;
	else return false;
}

// возвращает true, если в четырёхугольник может быть вписана окружность и false в противном случае
bool figure::is_out_circle()
{
	float AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	float BC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	float CD = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
	float AD = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));

	bool result = AB + CD == BC + AD;
	return result;
}

// Квадрат ли фигура
bool figure::is_square()
{
	float AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	float BC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	float CD = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
	float AD = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));

	float AC = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2)); // d1
	float BD = sqrt(pow(x4 - x2, 2) + pow(y4 - y2, 2)); // d2

	if (AB == BC && BC == CD && CD == AD && AD == AB && AC == BD) return true;
	else return false;
}

// Ромб ли фигура
bool figure::is_romb()
{
	float AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	float BC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	float CD = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
	float AD = sqrt(pow(x4 - x1, 2) + pow(y4 - y1, 2));

	float AC = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2)); // d1
	float BD = sqrt(pow(x4 - x2, 2) + pow(y4 - y2, 2)); // d2

	if (AB == BC && BC == CD && CD == AD && AD == AB) return true;
	else return false;
}