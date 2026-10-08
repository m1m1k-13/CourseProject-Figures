#pragma once
#include <windows.h>
#include <string>

class Figure {
public:
	Figure(int _x, int _y, int _r, COLORREF c);
	virtual void show() const;
	virtual void hide() const;
	void move(int dx, int dy);
	~Figure();
	class InvalidValue {
		public:
			InvalidValue(std::string mes) : message(mes) {};
			std::string getMessage() const { return message; }
		private:
			std::string message;
	};
protected:
	int x, y, r;
	HWND hwnd;
	HDC hdc;
	RECT rt;
	COLORREF color;
};