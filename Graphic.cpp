#include "Graphic.h"
#include "Utils.h"

#include <cstdio>
#include <iostream>

using std::cout;

void Graphic::drawGameName() {

	cout << "\t\t\t _____\n";
	cout << "\t\t\t|  __ \\ \n";
	cout << "\t\t\t| |__) |__  _ __   __ _\n";
	cout << "\t\t\t|  ___/ _ \\| '_ \\ / _` |\n";
	cout << "\t\t\t| |   |(_) | | | | (_| |\n";
	cout << "\t\t\t|_|   \\___/|_| |_|\\__, |\n";
	cout << "\t\t\t                   __/ |\n";
	cout << "\t\t\t                  |___/\n";

}
void Graphic::drawBall(Ball b) {
	Utils::gotoXY(b.getX(), b.getY());
	putchar('O');
}
void Graphic::deleteBall(Ball b) {
	Utils::gotoXY(b.getX(), b.getY());
	putchar(' ');
}

void Graphic::drawBoard(Board a)
{
	pair<int, int> b, c;
	// Rào trên
	b = a.getTopLeft();
	c = a.getTopRight();
	for (int x = b.first; x <= c.first; x++)
	{
		Utils::gotoXY(x, b.second);
		putchar(219);
	}

	// Rào dưới
	b = a.getBotLeft();
	c = a.getBotRight();
	for (int x = b.first; x <= c.first; x++)
	{
		Utils::gotoXY(x, b.second);
		putchar(219);
	}

	// Rào trái
	b = a.getTopLeft();
	c = a.getBotLeft();
	for (int y = b.second; y <= c.second; y++)
	{
		Utils::gotoXY(b.first, y);
		putchar(219);
	}

	// Rào phải
	b = a.getTopRight();
	c = a.getBotRight();
	for (int y = b.second; y <= c.second; y++)
	{
		Utils::gotoXY(b.first, y);
		putchar(219);
	}
}

void Graphic::drawStick(Stick s) {
	Utils::gotoXY(s.getX(), s.getY());
	for (int i = 0; i <= s.getsize(); i++) {
		putchar('*');
	}
}

void Graphic::deleteStick(Stick s) {

	Utils::gotoXY(s.getX(), s.getY());
	for (int i = 0; i <= s.getsize(); i++) {
		putchar(' ');
	}
}
