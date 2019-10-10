#include "Stick.h"
#include "Game.h"
#include "Utils.h"
#include <windows.h>
#include <cstdio>
#include <ctype.h>
#include <conio.h>




Stick::Stick()
{
	a.gotoXY(0, 0);
	diemDau = 0;
	diemCuoi = 6;
	Graphic::drawStick(diemDau, diemCuoi);
}

Stick::~Stick()
{

}

void Stick::setPlace(int x, int y)
{
	a.gotoXY(x, y);
	diemDau = x;
	diemCuoi = x + 6;
	Graphic::drawStick(diemDau, diemCuoi);
}

void Stick::moveLeft()
{
	Utils a;
	a.gotoXY(diemDau, HEIGHT);
	Graphic::deleteStick(diemDau, diemCuoi);
	diemDau = diemDau - 1;
	if (diemDau > 0)
	{
		diemCuoi = diemCuoi - 1;
		a.gotoXY(diemDau, HEIGHT);
		Graphic::drawStick(diemDau, diemCuoi);
	}
	else if (diemDau == 0)
	{
		diemDau = diemDau + 1;
		a.gotoXY(diemDau, HEIGHT);
		Graphic::drawStick(diemDau, diemCuoi);
	}
}

void Stick::moveRight()
{
	Utils a;
	a.gotoXY(diemDau, HEIGHT);
	Graphic::deleteStick(diemDau, diemCuoi);
	diemCuoi = diemCuoi + 1;
	if (diemCuoi < WIDTH)
	{
		diemDau = diemDau + 1;
		a.gotoXY(diemDau, HEIGHT);
		Graphic::drawStick(diemDau, diemCuoi);
	}
	else if (diemCuoi == WIDTH)
	{
		diemCuoi = diemCuoi - 1;
		a.gotoXY(diemDau, HEIGHT);
		Graphic::drawStick(diemDau, diemCuoi);
	}
}