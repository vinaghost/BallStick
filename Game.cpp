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
				
				player1.setBoard(board.getTopLeft().first, board.getTopLeft().second, board.getWidth(), board.getHeight());
				player1.setSize(setting::lengthStick[menuSetting.getLengthStick()]);
				player1.setX(board.getTopLeft().first + board.getWidth() / 2 - player1.getSize() / 2);
				player1.setY(board.getTopLeft().second + 1);


				player2.setBoard(board.getTopLeft().first, board.getTopLeft().second, board.getWidth(), board.getHeight());
				player2.setSize(setting::lengthStick[menuSetting.getLengthStick()]);
				player2.setX(board.getBotLeft().first + board.getWidth() / 2 - player2.getSize()/2);
				player2.setY(board.getBotLeft().second - 1);

				ball.setBoard(board.getTopLeft().first, board.getTopLeft().second, board.getWidth(), board.getHeight());

				Utils::clearScreen();

				board.showBoard();

				player1.spawn();
				player2.spawn();

				ball.setX(board.getTopLeft().first + board.getWidth() / 2);
				ball.setY(board.getTopLeft().second + board.getWidth() / 2);
				ball.spawn();

				point_player1 = 0;
				point_player2 = 0;

				Utils::gotoXY(5, board.getTopLeft().second + 5);
				printf("%d\t\t", point_player2);

				Utils::gotoXY(5, board.getBotLeft().second - 5);
				printf("%d\t\t", point_player1);

				this->tiepTuc = true;
				this->mode = menuSetting.getMode();

				while (isContinue()) {

					this->curTime = GetTickCount();

					if (this->curTime > this->startTime_player) {


						if (GetKeyState('A') & 0x8000) {
							player1.update(player1.getX() - 1);
						}

						if (GetKeyState('D') & 0x8000) {
							player1.update(player1.getX() + 1);
						}

						if (GetKeyState('J') & 0x8000 && this->mode == 0) {
							player2.update(player2.getX() - 1);
						}

						if (GetKeyState('L') & 0x8000 && this->mode == 0) {
							player2.update(player2.getX() + 1);
						}

						if (GetKeyState(VK_ESCAPE) & 0x8000) {
							this->tiepTuc = false;
						}

						//xử lí bot
						if (this->mode == 1) {
							if (ball.getX() > player2.getX())
								player2.update(player2.getX() + 1);
							else if (ball.getX() < player2.getX())
								player2.update(player2.getX() - 1);
						}


						this->startTime_player = this->curTime + setting::tick_player[menuSetting.getSpeedStick()];
					}

					if (this->curTime > this->startTime_ball) {

						int result = ball.update(player1, player2);

						switch (result) {
							//chạm biên trên, player 2 thua
							case 3:
								point_player1++;
								this->tick_ball_game = setting::tick_ball[menuSetting.getSpeedBall()];

								ball.despawn();
								ball.setX(board.getTopLeft().first + board.getWidth() / 2);
								ball.setY(board.getTopLeft().second + board.getHeight() / 2);
								ball.spawn();

								Utils::gotoXY(5, board.getBotLeft().second - 5);
								printf("%d\t\t", point_player1);
								
								break;
								//chạm biên dưới, player 1 thua
							case 4:
								point_player2++;
								this->tick_ball_game = setting::tick_ball[menuSetting.getSpeedBall()];
								ball.despawn();
								ball.setX(board.getTopLeft().first + board.getWidth() / 2);
								ball.setY(board.getTopLeft().second + board.getHeight() / 2);
								ball.spawn();


								Utils::gotoXY(5, board.getTopLeft().second + 5);
								printf("%d\t\t", point_player2);
								

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

void Game::moveRight_Player1() {
	player1.update(player1.getX() + 1);
}
void Game::moveLeft_Player1() {
	player1.update(player1.getX() - 1);
}

void Game::moveRight_Player2() {
	player2.update(player2.getX() + 1);
}
void Game::moveLeft_Player2() {
	player2.update(player2.getX() - 1);
}
