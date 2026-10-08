//Аникин Артём 24ВП2
//Курсовой проект
//Вариант 3
//Приложение на языке C++. Классы: прямоугольный треугольник, окружность

#include "Figure.h"
#include "Triangle.h"
#include "Circle.h"
#include "AgrigeFigure.h"
#include "StackVector.h"
#include <iostream>
using namespace std;

const int NotUsed = system("color F0");

int main() 
{
	SetConsoleTitle((LPCWSTR)L"24VP2_3");
	setlocale(LC_ALL, "");
	COORD p = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);

	try {
		Figure* s[] {
			new Triangle(300, 150, 120, RGB(220, 255, 160)),
			new Circle(700, 250, 100, RGB(220, 150, 160))
		};

		Triangle* triangle = new Triangle(480, 300, 160, RGB(220, 255, 100));
		Circle* circle = new Circle(400, 300, 80, RGB(220, 255, 100));
		AgrigeFigure AgrF(triangle, circle);

		//Прямоугольный треугольник
		s[0]->show();
		Sleep(1200);
		s[0]->move(-50, 20);
		Sleep(1200);
		s[0]->hide();

		//Окружность
		s[1]->show();
		Sleep(1200);
		s[1]->move(50, 20);
		Sleep(1200);
		s[1]->hide();

		//Сложная фигура
		AgrF.show();
		Sleep(1200);
		AgrF.move(70, 50);
		Sleep(1200);
		AgrF.hide();

		//Контейнер
		StackVector f{};
		f.add(s[0]);
		f.add(s[1]);
		f.add(AgrF);
		
		f.view();
		Sleep(1200);
		f.del();
		Sleep(12000);
	}
	catch (Figure::InvalidValue(ex)) {
		cout << ex.getMessage() << endl;
	}
}