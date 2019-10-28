#include "Game.h"
#include "Utils.h"
#include "Graphic.h"
#include "Menu.h"

#include <stdio.h>
#include <Windows.h>

Game::Game() {
	Utils::fixConsoleWindow();
	this->tiepTuc = true;
	this->choice = 0;

	this->startTime_player = 0;
	this->startTime_ball = 0;

	this->tick_ball_game = setting::tick_ball[menuSetting.getSpeedBall()];
	
	this->mode = true;

	menuMain.addItem("Start");
	menuMain.addItem("Setting");
	menuMain.addItem("Exit");

	menuMain.setCoordItem(30, 10);

	this->loop();
}

void Game::loop() {

	while (true) {
		Utils::clearScreen();
		menuMain.show();
		choice = menuMain.getChoice();

		switch (choice) {
			case 0:

				Utils::showConsoleCursor(false);
				
				board.setBoard(setting::boardTopLeft[menuSetting.getSizeBoard()].first, setting::boardTopLeft[menuSetting.getSizeBoard()].second, setting::boardWidth[menuSetting.getSizeBoard()], setting::boardHeight[menuSetting.getSizeBoard()]);
				

				pTop.setBoard(&board);
				pTop.setSize(setting::lengthStick[menuSetting.getLengthStick()]);
				pTop.setX(board.getTopLeft().first + board.getWidth() / 2 - pTop.getSize() / 2);
				pTop.setY(board.getTopLeft().second + 1);


				pBot.setBoard(&board);
				pBot.setSize(setting::lengthStick[menuSetting.getLengthStick()]);
				pBot.setX(board.getBotLeft().first + board.getWidth() / 2 - pBot.getSize()/2);
				pBot.setY(board.getBotLeft().second - 1);

				ball.setBoard(&board);

				Utils::clearScreen();

				board.showBoard();

				pTop.spawn();
				pBot.spawn();

				ball.setX(board.getTopLeft().first + board.getWidth() / 2);
				ball.setY(board.getTopLeft().second + board.getWidth() / 2);
				ball.spawn();

				this->tiepTuc = true;
				this->mode = menuSetting.getMode();

				while (isContinue()) {

					this->curTime = GetTickCount();

					if (this->curTime > this->startTime_player) {


						if (GetKeyState('A') & 0x8000) {
							pTop.update(pTop.getX() - 1);
						}

						if (GetKeyState('D') & 0x8000) {
							pTop.update(pTop.getX() + 1);
						}

						if (GetKeyState('J') & 0x8000 && this->mode == 0) {
							pBot.update(pBot.getX() - 1);
						}

						if (GetKeyState('L') & 0x8000 && this->mode == 0) {
							pBot.update(pBot.getX() + 1);
						}

						if (GetKeyState(VK_ESCAPE) & 0x8000) {
							this->tiepTuc = false;
						}

						//xử lí bot
						if (this->mode == 1) {
							if (ball.getX() > pBot.getX())
								pBot.update(pBot.getX() + 1);
							else if (ball.getX() < pBot.getX())
								pBot.update(pBot.getX() - 1);
						}


						this->startTime_player = this->curTime + setting::tick_player[menuSetting.getSpeedStick()];
					}

					if (this->curTime > this->startTime_ball) {

						int result = ball.update(pTop, pBot);

						switch (result) {
							//chạm biên trên, pTop thắng
							case 3:
								this->tick_ball_game = setting::tick_ball[menuSetting.getSpeedBall()];

								ball.despawn();
								ball.setX(board.getTopLeft().first + board.getWidth() / 2);
								ball.setY(board.getTopLeft().second + board.getHeight() / 2);
								ball.spawn();
								
								break;
								//chạm biên dưới, pBot thắng
							case 4:
								this->tick_ball_game = setting::tick_ball[menuSetting.getSpeedBall()];
								ball.despawn();
								ball.setX(board.getTopLeft().first + board.getWidth() / 2);
								ball.setY(board.getTopLeft().second + board.getHeight() / 2);
								ball.spawn();								

								break;

							//chạm stick trên
							case 5:
							//chạm stick dưới
							case 6:
								// tăng 10% tốc độ
								this->tick_ball_game -= setting::tick_ball[menuSetting.getSpeedBall()] / 10;
								break;
						}

						
						this->startTime_ball = this->curTime + this->tick_ball_game;

					}

				}

				Utils::showConsoleCursor(true);

				break;
			case 1:
				menuSetting.show();
				break;
			case 2:
				return;
		}


	}
}
bool Game::isContinue() {
	return tiepTuc;
}

void Game::moveRight_pTop() {
	pTop.update(pTop.getX() + 1);
}
void Game::moveLeft_pTop() {
	pTop.update(pTop.getX() - 1);
}

void Game::moveRight_pBot() {
	pBot.update(pBot.getX() + 1);
}
void Game::moveLeft_pBot() {
	pBot.update(pBot.getX() - 1);
}
