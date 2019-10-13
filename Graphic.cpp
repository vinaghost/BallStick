#include <cstdio>

#include "Graphic.h"
#include "Utils.h"

#include <iostream>

using std::cout;

void Graphic::drawGameName() {
	                              
	cout << " _____\n";
	cout << "|  __ \\ \n";
	cout << "| |__) |__  _ __   __ _\n";
	cout << "|  ___/ _ \\| '_ \\ / _` |\n";
	cout << "| |   |(_) | | | | (_| |\n";
	cout << "|_|   \\___/|_| |_|\\__, |\n";
	cout << "                   __/ |\n";
	cout << "                  |___/\n";

}
void Graphic::drawBall(Ball b) {
	Utils::gotoXY(b.getX(), b.getY());
	putchar('O');
}
void Graphic::deleteBall(Ball b) {
	Utils::gotoXY(b.getX(), b.getY());
	putchar(' ');
}
void Graphic::drawStick(int x, int y, int z)
{
	Utils::gotoXY(x, z);
	for (int i = x; i <= x + y; i++)
	{
		putchar('*');
	}
}

void Graphic::deleteStick(int x, int y, int z)
{
	Utils::gotoXY(x, z);
	for (int i = x; i <= x + y; i++)
	{
		putchar(' ');
	}
}