#pragma once
#include "Ball.h"
#include "Stick.h"
#include "Board.h"
#include "Menu.h"

class Game {
private:

	int choice;
	bool tiepTuc;
	Ball* ball;
	Stick *player1;
	Stick *player2;

	Board *board;

	int point_player1;
	int point_player2;

	Menu menuMain;

	unsigned long startTime_player;
	unsigned long startTime_ball;
	unsigned long curTime;

	const int tick_player = 0;
	const int tick_ball = 200;

	int tick_ball_game;

public:
	Game();
	~Game();

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
	* Xử lí các sự kiện trong game
	*
	* @note
	*
	*
	* @noreturn
	**/
	void loop();

	/**
	* Gọi khi nút qua phải của player 1 được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	void moveRight_Player1();

	/**
	* Gọi khi nút qua trái của player 2 được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	void moveLeft_Player1();

	/**
	* Gọi khi nút qua phải của player 2 được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	void moveRight_Player2();

	/**
	* Gọi khi nút qua trái của player 2 được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	void moveLeft_Player2();
};
