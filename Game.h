﻿#pragma once
#include "Ball.h"
#include "Stick.h"
#include "Board.h"
#include "Menu.h"

class Game
{
private:
	int command;
	bool tiepTuc;
	Ball* ball;
	Stick *player1;
	Stick *player2;

	Board* board;

	Menu menuMain;

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
