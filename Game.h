#pragma once
#include "Ball.h"
#include "Stick.h"
#include "Board.h"
#include "Menu.h"
#include "MenuSetting.h"

namespace setting {
	
	//length stick
	const int lengthStick[3] = { 3, 5, 9 };

	//size board 
	const pair<int, int> boardTopLeft[3] = {
		{26 , 10},
		{20 , 10},
		{14 , 10}
	};

	const int boardWidth[3] = { 20, 30, 40 };
	const int boardHeight[3] = { 20, 25, 30 };


	const int tick_player[3] = { 50, 30, 0 };
	const int tick_ball[3] = { 500, 200, 100 };

};

class Game {
private:
	int choice;
	bool tiepTuc;
	bool newRound;
	int winner;

	Board board;

	Ball ball;
	Stick pTop;
	Stick pBot;
	
	bool mode;
	
	Menu menuMain;
	MenuSetting menuSetting;
	Menu menuContinue;


	//Biến quản lí thời gian
	unsigned long startTime_player;
	unsigned long startTime_ball;
	unsigned long curTime;
	
	int tick_ball_game;

public:
	Game();

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
	* Trả về giá trị của Game::newRound
	*
	* @note
	*
	*
	* @return giá trị true hoặc false của Game::newRound
	**/
	bool isNewRound();

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
	void moveRight_pTop();

	/**
	* Gọi khi nút qua trái của player 2 được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	void moveLeft_pTop();

	/**
	* Gọi khi nút qua phải của player 2 được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	void moveRight_pBot();

	/**
	* Gọi khi nút qua trái của player 2 được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	void moveLeft_pBot();


	void showWinner(int who);
};
