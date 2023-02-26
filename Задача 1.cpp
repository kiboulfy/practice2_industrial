#include <iostream>
#include <cmath>
#include <locale>
#include "Triangle.h"

int main()
{
    setlocale(LC_ALL, "");
    Triangle mas[3];
    double a, b, c;
    for (int i = 0; i < 3; i++) {
        std::cout << "Введите a, b и c для треугольника № " << i + 1 << " через пробел: " << std::endl;
        std::cin >> a >> b >> c;
        mas[i].set(a, b, c);
        if (!(mas[i].exst_tr())) {
            mas[i].show();
            std::cout << "Треугольника с такими сторонами не существует, попробуйте ещё раз" << std::endl;
            i--;
        }
    }
    for (int i = 0; i < 3; i++) {
        mas[i].show();
        std::cout << "Периметр треугольника: " << mas[i].perimetr() << std::endl;
        std::cout << "Площадь треугольника: " << mas[i].square() << std::endl;
    }
    return 0;
}