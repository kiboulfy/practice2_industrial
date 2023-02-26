#include <iostream>
#include <locale>
#include "figure.h"

int main() {
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "en_US.UTF-8");

	float x1, x2, x3, x4, y1, y2, y3, y4;
	std::cout << "Введите координаты точек фигуры(x1,x2,x3,x4,y1,y2,y3,y4): " << std::endl;
	std::cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
	figure f1(x1, x2, x3, x4, y1, y2, y3, y4);
	std::cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
	figure f2(x1, x2, x3, x4, y1, y2, y3, y4);
	std::cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
	figure f3(x1, x2, x3, x4, y1, y2, y3, y4);

	figure mas[] = { f1, f2, f3 };

	for (int i = 0; i < 3; i++)
	{
		printf("=== >>> Фигура %d <<< ===\n", i + 1);
		mas[i].show();
		if (mas[i].is_prug()) printf("Это прямоугольник\n");
		else printf("Это не прямоугольник\n");
		if (mas[i].is_square()) printf("Это квадрат\n");
		else printf("Это не квадрат\n");
		if (mas[i].is_romb()) printf("Это ромб\n");
		else printf("Это не ромб\n");
		if (mas[i].is_in_circle()) printf("Это фигура, которую можно вписать в окружность\n");
		else printf("Это фигура, которую нельзя вписать в окружность\n");
		if (mas[i].is_out_circle()) printf("Это фигура, которую можно описать окружностью\n");
		else printf("Это фигура, которую нельзя описать окружностью\n");
		printf("\n");
	}

	return 0;
}