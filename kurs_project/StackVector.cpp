#include "StackVector.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void StackVector::add(Figure* f) { 
	sv.push(f); 
};

void StackVector::add(AgrigeFigure f) {
	sv.push(f.triangle);
	sv.push(f.circle);
};

void StackVector::view() {
	//cout << "Контейнер:" << endl;
	stack<Figure*, vector<Figure*>> copy;
	while (!sv.empty()) {
		sv.top()->show();
		copy.push(sv.top());
		sv.pop();
	}
	while (!copy.empty()) {
		sv.push(copy.top());
		copy.pop();
	}
};

void StackVector::del() {
	while (!sv.empty()) sv.pop();
};