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
	void SticktoLeft_Duoi();
	/**
	* Điều khiển thanh dưới qua phải
	*
	* @note
	*
	* @noreturn
	**/
	void SticktoRight_Duoi();
	/**
	* Điều khiển thanh trên qua trái
	*
	* @note
	*
	* @noreturn
	**/
	void SticktoLeft_Tren();
	/**
	* Điều khiển thanh trên qua phải
	*
	* @note
	*
	* @noreturn
	**/
	void SticktoRight_Tren();
};
