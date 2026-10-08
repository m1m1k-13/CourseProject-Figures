#include "Figure.h"
#include <iostream>
#include <string>
using namespace std;

Figure::Figure(int _x, int _y, int _r, COLORREF c) : x(_x), y(_y), r(_r), color(c) {
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	GetClientRect(hwnd, &rt);
};

void Figure::show() const {
	cout << x << ", " << y << ", " << r << endl;
};

void Figure::hide() const {};

void Figure::move(int dx, int dy) {
	hide();
	x += dx; y += dy;
	show();
};

Figure::~Figure() {
	ReleaseDC(hwnd, hdc);
}