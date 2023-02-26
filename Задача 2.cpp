#include <iostream>
#include <locale>
#include "circle.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "en_EN.utf8");
	circle mas[3];

	for (int i = 0; i < 3; i++)
	{
		float r, x, y;
		std::cout << "Введите радиус, координаты центра " << i + 1 << "-й окружности через пробел : ";
		std::cin >> r >> x >> y;
		mas[i].set_circle(r, x, y);
	}

	for (int i = 0; i < 3; i++)
	{
		float a, b, c;
		std::cout << "Введите стороны " << i + 1 << "-го треугольника через пробел : ";
		std::cin >> a >> b >> c;
		if (mas[i].triangle_around(a, b, c)) std::cout << "Треугольник описывается окружностью" << std::endl;
		else std::cout << "Треугольник не описывается окружностью" << std::endl;
		if (mas[i].triangle_in(a, b, c)) std::cout << "Треугольник вписывается в окружность" << std::endl;
		else std::cout << "Треугольник не вписывается в окружность" << std::endl;
	}

	for (int i = 0; i < 3; i++) {
		float x, y;
		std::cout << "Введите координаты центра " << i + 1 << "-й окружности через пробел : ";
		std::cin >> x >> y;
		if (mas[i].check_circle(x, y)) std::cout << "Окружность пересекается с " << i + 1 << "-й окружностью" << std::endl;
		else std::cout << "Окружность не пересекается с " << i + 1 << "-й окружностью" << std::endl;
	}
	return 0;
}