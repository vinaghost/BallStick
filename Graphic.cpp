#include "Graphic.h"

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