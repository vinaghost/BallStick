#include "Graphic.h"

void Graphic::drawStick(int x, int y)
{
	for (int i = x; i <= y; i++)
	{
		putchar('*');
	}
}

void Graphic::deleteStick(int x, int y)
{
	for (int i = x; i <= y; i++)
	{
		putchar(' ');
	}
}