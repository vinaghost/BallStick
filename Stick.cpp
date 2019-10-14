#include "Stick.h"


#include "Graphic.h"
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

void Stick::update(int x, int y) {
	
	Graphic::deleteStick(*this);

	this->setX(x);
	this->setX(y);

	Graphic::drawStick(*this);
}