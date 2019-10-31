#include "Game.h"
#include "Utils.h"
#include "Graphic.h"
#include "Menu.h"

#include <iostream>
#include <Windows.h>

using std::cout;

Game::Game() {
	Utils::fixConsoleWindow();
	
	this->choice = 0;

	this->startTime_player = 0;
	this->startTime_ball = 0;
	
	menuMain.addItem("Bat dau");
	menuMain.addItem("Setting");
	menuMain.addItem("Thoat");

	menuMain.setCoordItem(30, 10);

	menuContinue.addItem("Tiep tuc");
	menuContinue.addItem("Tro lai menu chinh");
	menuContinue.setCoordItem(25, 20);


	this->loop();
}

void Game::loop() {

	while (true) {
		Utils::clearScreen();
		Utils::playSound("music\\background.wav", true);
		menuMain.show();
		choice = menuMain.getChoice();

		switch (choice) {
			case 0:

				Utils::playSound("");
				this->newRound = true;
				while (isNewRound()) {
					Utils::showConsoleCursor(false);

					this->winner = -1;
					this->tiepTuc = true;
					this->mode = menuSetting.getMode();

					this->tick_ball_game = setting::tick_ball[menuSetting.getSpeedBall()];


					board.setBoard(setting::boardTopLeft[menuSetting.getSizeBoard()].first, setting::boardTopLeft[menuSetting.getSizeBoard()].second, setting::boardWidth[menuSetting.getSizeBoard()], setting::boardHeight[menuSetting.getSizeBoard()]);

					pTop.setBoard(&board);
					pTop.setSize(setting::lengthStick[menuSetting.getLengthStick()]);
					pTop.setX(board.getTopLeft().first + board.getWidth() / 2 - pTop.getSize() / 2);
					pTop.setY(board.getTopLeft().second + 1);
					pTop.setColor(4); //đỏ

					pBot.setBoard(&board);
					pBot.setSize(setting::lengthStick[menuSetting.getLengthStick()]);
					pBot.setX(board.getBotLeft().first + board.getWidth() / 2 - pBot.getSize() / 2);
					pBot.setY(board.getBotLeft().second - 1);
					pBot.setColor(10); //xanh lá

					ball.setBoard(&board);

					Utils::clearScreen();

					board.showBoard();

					pTop.spawn();
					pBot.spawn();

					ball.reset();

					while (isContinue()) {

						this->curTime = GetTickCount();

						if (this->curTime > this->startTime_player) {


							if (GetKeyState('A') & 0x8000) {
								pBot.update(pBot.getX() - 1);
							}

							if (GetKeyState('D') & 0x8000) {
								pBot.update(pBot.getX() + 1);
							}

							if (GetKeyState('J') & 0x8000 && this->mode == 0) {
								pTop.update(pTop.getX() - 1);
							}

							if (GetKeyState('L') & 0x8000 && this->mode == 0) {
								pTop.update(pTop.getX() + 1);
							}

							if (GetKeyState(VK_ESCAPE) & 0x8000) {
								this->tiepTuc = false;
								this->newRound = false;

								pTop.despawn();
								pBot.despawn();
								ball.despawn();
							}

							//xử lí bot
							if (this->mode == 1) {
								if (ball.getX() > pTop.getX()) {
									pTop.update(pTop.getX() + 1);
								}
								else if (ball.getX() < pTop.getX()) {
									pTop.update(pTop.getX() - 1);
								}
							}


							this->startTime_player = this->curTime + setting::tick_player[menuSetting.getSpeedStick()];
						}

						if (this->curTime > this->startTime_ball) {

							int result = ball.update(pTop, pBot);

							switch (result) {
								//chạm biên trên, pBot thắng
								case 3:
									this->tick_ball_game = setting::tick_ball[menuSetting.getSpeedBall()];
									this->winner = 2;
									Utils::playSound("music\\win_music.wav");
									break;
									//chạm biên dưới, pTop thắng
								case 4:
									this->tick_ball_game = setting::tick_ball[menuSetting.getSpeedBall()];
									
									if (this->mode == 1) {
										this->winner = 0;
										Utils::playSound("music\\lose_music.wav");
									}
									else {
										this->winner = 1;
										Utils::playSound("music\\win_music.wav");
									}
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

						if (winner != -1) {
							
							this->tiepTuc = false;

							pTop.despawn();
							pBot.despawn();
							ball.despawn();

							Utils::clearScreen();
							for (int i = 0; i < 10; i++) {
								cout << "\n";
							}
							showWinner(winner);

							Utils::gotoXY(0, 0);
							Utils::showConsoleCursor(true);
							menuContinue.show();


							choice = menuContinue.getChoice();

							if (choice == 1) {
								this->newRound = false;
							}
							Utils::playSound(NULL);
						}
					}
					Utils::showConsoleCursor(true);
				}
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

bool Game::isNewRound() {
	return newRound;
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

void Game::showWinner(int who) {
	switch (who) {
		case 0: // máy
			Graphic::drawPlayerLose();
			break;
		case 1: // top thắng
			Utils::setColorText(10, 0);
			Graphic::drawPlayerWin();

			for (int i = 0; i < 14; i++) {
				cout << "\n";
			}

			Utils::setColorText(4, 0);
			Graphic::drawPlayerLose();

			Utils::setColorText(15, 0);
			break;
		case 2: // bottom thắng

			if (this->mode == 0) {
				Utils::setColorText(4, 0);
				Graphic::drawPlayerLose();


				for (int i = 0; i < 14; i++) {
					cout << "\n";
				}
			}

			Utils::setColorText(10, 0);
			Graphic::drawPlayerWin();

			Utils::setColorText(15, 0);
			break;
	}
}