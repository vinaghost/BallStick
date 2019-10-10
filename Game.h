﻿#pragma once
#include "Ball.h"


#include <stdio.h>
#include <ctype.h>
#include <conio.h>

class Game
{
private:
	int command;
	bool tiepTuc;
	Ball* b;
public:
	Game();
	~Game();

	/**
	* Lấy nút nhập từ bàn phím
	*
	* @note Dùng hàm _getch() làm hàm nhập nên
	*		không hiện nút đã nhập lên bàn phím đồng
	*		thời không cần phải nhấn Enter
	*
	*
	* @return mã ASCII của nút đã nhập
	**/
	int getCommand();

	/**
	* Trả về giá trị của Game::tiepTuc
	*
	* @note
	*
	*
	* @return giá trị true hoặc false của Game::tiepTuc
	**/
	bool isContinue();

	/**
	* Lấy nút nhập từ bàn phím
	*
	* @note Dùng hàm _getch() làm hàm nhập nên
	*		không hiện nút đã nhập lên bàn phím đồng
	*		thời không cần phải nhấn Enter
	*
	*
	* @return mã ASCII của nút đã nhập
	**/
	int waitKeyBoard();

	/**
	* Xử lí các sự kiện trong game
	*
	* @note 
	*
	*
	* @noreturn
	**/
	void loop();
	/**
	* Gọi khi nút qua phải được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	void moveRight();

	/**
	* Gọi khi nút qua trái được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	void moveLeft();
};
