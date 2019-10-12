#include "Stick.h"
#include "Game.h"
#include "Utils.h"
#include <windows.h>
#include <cstdio>
#include <ctype.h>
#include <conio.h>




Stick::Stick(int height, int width	)
{
	x = 0;
	y = 0;
	size = 0;
}

Stick::~Stick()
{

}

void Stick::setX(int x)
{
	this->x = x;
}

void Stick::setY(int y)
{
	this->y = y;
}

int Stick::getX()
{
	return this->x;
}

int Stick::getY()
{
	return this->y;
}

void Stick::setSize(int size)
{
	this->size = size;
}

void Stick::setPlace()
{
	Utils::gotoXY(x, y);
}

void Stick::update(int chon)
{
	if (chon == 1) //moveLeft
	{
		Utils::gotoXY(x, height);
		Graphic::deleteStick(x, x + size);
		x = x - 1;
		int a = x + size;
		if (x > 0)
		{
			a = a - 1;
			Utils::gotoXY(x, height);
			Graphic::drawStick(x, a);
		}
		else if (x == 0)
		{
			x = x + 1;
			Utils::gotoXY(x, height);
			Graphic::drawStick(x, a);
		}
	}
	else if (chon == 2)  //moveRight
	{
		int a = x + size;
		Utils::gotoXY(x, height);
		Graphic::deleteStick(x, a);
		a = a + 1;
		if (a < width)
		{
			x = x + 1;
			Utils::gotoXY(x, height);
			Graphic::drawStick(x, a);
		}
		else if (a = width)
		{
			a = a - 1;
			Utils::gotoXY(x, height);
			Graphic::drawStick(x, a);
		}
	}
}