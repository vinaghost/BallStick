#include "Stick.h"
#include "Game.h"
#include "Utils.h"
#include <windows.h>
#include <cstdio>
#include <ctype.h>
#include <conio.h>




Stick::Stick()
{
	diemDau = (WIDTH / 2);
	diemCuoi = (WIDTH / 2) + 5;
	for (int i = diemDau; i <= diemCuoi; i++)
	{
		putchar('*');
	}
}

Stick::~Stick()
{

}

void Stick::toLeft_Duoi()
{
	Utils a;
	a.gotoXY(diemDau, HEIGHT);
	for (int i = diemDau; i <= diemCuoi; i++)
	{
		putchar('_');
	}
	diemDau = diemDau - 1;
	if (diemDau > 0)
	{
		diemCuoi = diemCuoi - 1;
		a.gotoXY(diemDau, HEIGHT);
		for (int i = diemDau; i <= diemCuoi; i++)
		{
			putchar('*');
		}
	}
	else if (diemDau == 0)
	{
		diemDau = diemDau + 1;
		a.gotoXY(diemDau, HEIGHT);
		for (int i = diemDau; i <= diemCuoi; i++)
		{
			putchar('*');
		}
	}
}

void Stick::toRight_Duoi()
{
	Utils a;
	a.gotoXY(diemDau, HEIGHT);
	for (int i = diemDau; i <= diemCuoi; i++)
	{
		putchar('_');
	}
	diemCuoi = diemCuoi + 1;
	if (diemCuoi < WIDTH)
	{
		diemDau = diemDau + 1;
		a.gotoXY(diemDau, HEIGHT);
		for (int i = diemDau; i <= diemCuoi; i++)
		{
			putchar('*');
		}
	}
	else if (diemCuoi == WIDTH)
	{
		diemCuoi = diemCuoi - 1;
		a.gotoXY(diemDau, HEIGHT);
		for (int i = diemDau; i <= diemCuoi; i++)
		{
			putchar('*');
		}
	}
}

void Stick::toLeft_Tren()
{
	Utils a;
	a.gotoXY(diemDau, 0);
	for (int i = diemDau; i <= diemCuoi; i++)
	{
		putchar('_');
	}
	diemDau = diemDau - 1;
	if (diemDau > 0)
	{
		diemCuoi = diemCuoi - 1;
		a.gotoXY(diemDau, 0);
		for (int i = diemDau; i <= diemCuoi; i++)
		{
			putchar('*');
		}
	}
	else if (diemDau == 0)
	{
		diemDau = diemDau + 1;
		a.gotoXY(diemDau, 0);
		for (int i = diemDau; i <= diemCuoi; i++)
		{
			putchar('*');
		}
	}
}

void Stick::toRight_Tren()
{
	Utils a;
	a.gotoXY(diemDau, 0);
	for (int i = diemDau; i <= diemCuoi; i++)
	{
		putchar('_');
	}
	diemCuoi = diemCuoi + 1;
	if (diemCuoi < WIDTH)
	{
		diemDau = diemDau + 1;
		a.gotoXY(diemDau, 0);
		for (int i = diemDau; i <= diemCuoi; i++)
		{
			putchar('*');
		}
	}
	else if (diemCuoi == WIDTH)
	{
		diemCuoi = diemCuoi - 1;
		a.gotoXY(diemDau, 0);
		for (int i = diemDau; i <= diemCuoi; i++)
		{
			putchar('*');
		}
	}
}