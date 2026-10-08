#pragma once
#include "Figure.h"
#include "AgrigeFigure.h"
#include <stack>
#include <vector>
using namespace std;

class StackVector {
private:
	stack<Figure*, vector<Figure*>> sv;
public:
	StackVector() {};
	void add(Figure* f);
	void add(AgrigeFigure f);
	void view();
	void del();
};