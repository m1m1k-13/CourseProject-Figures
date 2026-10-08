#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(int x, int y, int rad, COLORREF brush) : Figure(x, y, rad, brush) {
	if (x < 0 || y < 0) throw InvalidValue("Ошибка создания окружности:\nЗначения координат (" + to_string(x) + ", " + to_string(y) + ") не могут быть меньше 0!");
	if (rad <= 0) throw InvalidValue("Ошибка создания окружности:\nРадиус (" + to_string(rad) + ") не может быть меньше или равен 0!");
};

void Circle::show() const {

	int left_x = x - r;
	int top_y = y - r;
	int right_x = x + r;
	int down_y = y + r;
	string wnd = "Окно: " + to_string(rt.left) + ", " + to_string(rt.top) + ", " + to_string(rt.right) + ", " + to_string(rt.bottom) + "\n";
	if (left_x <= rt.left) throw InvalidValue("Выход окружности за левую границу окна!\n" + wnd + "Абсцисса левой точки: " + to_string(left_x));
	if (top_y <= rt.top) throw InvalidValue("Выход окружности за верхнюю границу окна!\n" + wnd + "Ордината верхней точки: " + to_string(top_y));
	if (right_x >= rt.right) throw InvalidValue("Выход окружности за правую границу окна!\n" + wnd + "Абсцисса правой точки: " + to_string(right_x));
	if (down_y >= rt.bottom) throw InvalidValue("Выход окружности за нижнюю границу окна!\n" + wnd + "Ордината нижней точки: " + to_string(down_y));

	//cout << "Окружность: ";
	//Figure::show();
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	HBRUSH brush = CreateSolidBrush(color);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, x - r, y - r, x + r, y + r);
	DeleteObject(pen);
	DeleteObject(brush);
};

void Circle::hide() const {
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));
	HBRUSH brush = CreateSolidBrush(RGB(242, 242, 242));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, x - r, y - r, x + r, y + r);
	DeleteObject(pen);
	DeleteObject(brush);
};