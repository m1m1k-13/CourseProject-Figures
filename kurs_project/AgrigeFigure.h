#pragma once
#include "Triangle.h"
#include "Circle.h"

class AgrigeFigure {
public:
	Triangle* triangle;
	Circle* circle;
	AgrigeFigure(Triangle* t, Circle* c);
	void show() const;
	void hide() const;
	void move(int dx, int dy);
};