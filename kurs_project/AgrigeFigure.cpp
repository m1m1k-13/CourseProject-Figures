#include "AgrigeFigure.h"
#include <iostream>
using namespace std;

AgrigeFigure::AgrigeFigure(Triangle* t, Circle* c) : triangle(t), circle(c) {};

void AgrigeFigure::show() const {
	//cout << "Сложная фигура: " << endl;
	circle->show();
	triangle->show();
};

void AgrigeFigure::hide() const {
	circle->hide();
	triangle->hide();
};

void AgrigeFigure::move(int dx, int dy) {
	circle->move(dx, dy);
	triangle->move(dx, dy);
	AgrigeFigure::show();
};