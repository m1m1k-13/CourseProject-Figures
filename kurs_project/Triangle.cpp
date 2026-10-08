#include "Triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle(int x, int y, int c, COLORREF brush) : Figure(x, y, c, brush) {
	if (x < 0 || y < 0) throw InvalidValue( "Ошибка создания прямоугольного трегольника:\nЗначения координат (" + to_string(x) + ", " + to_string(y) + ") не могут быть меньше 0!");
	if (c <= 0) throw InvalidValue("Ошибка создания прямоугольного трегольника:\nДлина гипотенузы (" + to_string(r) + ") не может быть меньше или равна 0!");
};

void Triangle::show() const {
	int left_x = x - r / 2;
	int left_top_y = y - r / 2;
	int right_down_y = y + r / 2;
	string wnd = "Окно: " + to_string(rt.left) + ", " + to_string(rt.top) + ", " + to_string(rt.right) + ", " + to_string(rt.bottom) + "\n";
	if (left_x <= rt.left) throw InvalidValue("Выход треугольника за левую границу окна!\n" + wnd + "Абсцисса левой точки: " + to_string(left_x));
	if (left_top_y <= rt.top) throw InvalidValue("Выход треугольника за верхнюю границу окна!\n" + wnd + "Ордината верхней точки: " + to_string(left_top_y));
	if (x >= rt.right) throw InvalidValue("Выход треугольника за правую границу окна!\n" + wnd + "Абсцисса правой точки: " + to_string(x));
	if (right_down_y >= rt.bottom) throw InvalidValue("Выход треугольника за нижнюю границу окна!\n" + wnd + "Ордината нижней точки: " + to_string(right_down_y));
	
	//cout << "Прямоугольный треугольник: ";
	//Figure::show();
	POINT points[] = {
		{x, y},
		{left_x, right_down_y},
		{left_x, left_top_y}
	};

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	HBRUSH brush = CreateSolidBrush(color);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Polygon(hdc, points, 3);
	DeleteObject(pen);
	DeleteObject(brush);
};

void Triangle::hide() const {
	POINT points[] = {
		{x, y},
		{x - r / 2, y + r / 2},
		{x - r / 2, y - r / 2}
	};

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));
	HBRUSH brush = CreateSolidBrush(RGB(242, 242, 242));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Polygon(hdc, points, 3);
	DeleteObject(pen);
	DeleteObject(brush);
};