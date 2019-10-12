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
	static int x, y, size;
	static int height, width;
public:
	Stick() = delete;
	Stick(int height, int width);
	~Stick();
	/**
	* Gán hoành độ cho điểm đầu của Stick
	*
	* @note  Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param x	hoành độ
	* @noreturn
	**/
	void setX(int x);
	/**
	* Gán tung độ cho điểm đầu của Stick
	*
	* @note  Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param x	hoành độ
	*
	* @noreturn
	**/
	void setY(int y);
	/**
	* Khởi tạo đồ dài cho Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param y	tung độ
	* @noreturn
	**/
	void setSize(int size);
	/**
	* Trả về hoành độ cho điểm đầu của Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param x	hoành độ
	*
	* @return (int) hoành độ cho Stick
	**/
	int getX();
	/**
	* Trả về tung độ cho điểm đầu của Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param y	tung độ
	*
	* @return (int) tung độ cho Stick
	**/
	int getY();
	/**
	* Khởi tạo vị trí ban đầu cho Stick
	*
	* @note
	*
	* @noreturn
	**/
	void setPlace();
	/**
	* Thay đổi vị trí của Stick
	*
	* @note  Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @noreturn
	**/
	static void update(int chon);
};
