#include "stdfx.h"
#include "pch.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

void main()
{
	double x, y;
	setlocale(LC_ALL, "Russian");
	int i = 0;
	while (i<3)
	{
	std::cout << "Введите x=";
		std::cin >> x;
		y = ((pow(sin(x + M_PI), 2)*pow(2, 1 - x)) / (4 * tan(abs(x))*sin(28 * M_PI / 180)*exp(-M_PI * x))) + 1. / 3 * log2(abs(x));
		std::cout << "y=" << y<< endl;
		i = i++;
	}
	getchar();
	system("pause");
}

