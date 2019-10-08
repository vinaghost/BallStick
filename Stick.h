#pragma once
#include "Utils.h"
#include <windows.h>
#include <cstdio>
#include <ctype.h>
#include <conio.h>

class Stick
{
private:
	int diemDau, diemCuoi;
public:
	Stick();
	~Stick();
	void toLeft_Duoi();
	void toRight_Duoi();
	void toLeft_Tren();
	void toRight_Tren();
};