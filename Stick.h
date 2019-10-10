#pragma once
#include "Utils.h"
#include <windows.h>
#include <cstdio>
#include <ctype.h>
#include <conio.h>
#include "Graphic.h"

class Stick
{
private:
	int diemDau, diemCuoi;
	Utils a;
public:
	Stick();
	~Stick();
	/**
	* Khởi tạo vị trí ban đầu cho Stick
	*
	* @note
	*
	* @noreturn
	**/
	void setPlace(int x, int y);
	/**
	* Điều khiển thanh qua trái
	*
	* @note
	*
	* @noreturn
	**/
	void moveLeft();
	/**
	* Điều khiển thanh  qua phải
	*
	* @note
	*
	* @noreturn
	**/
	void moveRight();
};
