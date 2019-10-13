#include "Stick.h"
#include "Game.h"
#include "Utils.h"
#include <windows.h>
#include <cstdio>
#include <ctype.h>
#include <conio.h>


Stick::Stick(int height, int width):  height(height), width(width)
{
	x = width/2;
	y = height;
	size = 3;
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

int Stick::getHeight()
{
	return this->height;
}

int Stick::getWidth()
{
	return this->width;
}

int Stick::getsize()
{
	return this->size;
}

void Stick::setPlace()
{
	Utils::gotoXY(x, y);
}

void Stick::update(int chon)
{
	if (chon == 1) //moveLeft
	{
		Graphic::deleteStick(x, size, height);
		x = x - 1;
		if (x > 0)
		{
			Graphic::drawStick(x, size, height);
		}
		else if (x == 0)
		{
			x = x + 1;
			Graphic::drawStick(x, size, height);
		}
	}
	else if (chon == 2)  //moveRight
	{
		Graphic::deleteStick(x, size, height);
		x = x + 1;
		if (x + size < width)
		{
			Graphic::drawStick(x, size, height);
		}
		else if ((x + size) == width)
		{
			x = x - 1;
			Graphic::drawStick(x, size, height);
		}
	}
}