#pragma once
#include "Figure.h"

class Triangle : public Figure {
public:
	Triangle(int x, int y, int c, COLORREF brush);
	void show() const override;
	void hide() const override;
};