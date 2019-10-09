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
	/**
	* Điều khiển thanh dưới qua trái
	*
	* @note 
	*
	* @noreturn
	**/
	void toLeft_Duoi();
	/**
	* Điều khiển thanh dưới qua phải
	*
	* @note
	*
	* @noreturn
	**/
	void toRight_Duoi();
	/**
	* Điều khiển thanh trên qua trái
	*
	* @note
	*
	* @noreturn
	**/
	void toLeft_Tren();
	/**
	* Điều khiển thanh trên qua phải
	*
	* @note
	*
	* @noreturn
	**/
	void toRight_Tren();
};
