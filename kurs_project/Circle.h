#pragma once
#include "Figure.h"

class Circle : public Figure {
public:
	Circle(int x, int y, int rad, COLORREF brush);
	void show() const override;
	void hide() const override;
};