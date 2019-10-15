#include "Game.h"
#include "Utils.h"
#include "Graphic.h"
#include "Menu.h"

#include <stdio.h>
#include <Windows.h>

Game::Game() {
	this->tiepTuc = true;
	this->choice = 0;

	this->startTime_player = 0;
	this->startTime_ball = 0;

	board = NULL;
	player1 = NULL;
	player2 = NULL;
	ball = NULL;

	menuMain.addItem("Start");
	menuMain.addItem("Exit");

	menuMain.setCoordItem(20, 10);

	this->loop();
}


Game::~Game() {
	if (board != NULL) {
		delete board;
	}
	if (player1 != NULL) {
		delete player1;
	}
	if (player2 != NULL) {
		delete player2;
	}
	if (ball != NULL) {
		delete ball;
	}
}

void Game::loop() {
	
	while (true) {
		Utils::clearScreen();
		menuMain.show();
		choice = menuMain.getChoice();

		switch (choice) {
			case 0:
				
				Utils::showConsoleCursor(false);
				if (board != NULL) {
					delete board;
				}
				board = new Board({ 10, 9 }, 20, 10);

				if (player1 != NULL) {
					delete player1;
				}
				player1 = new Stick(board->getTopLeft().first, board->getTopLeft().second, board->getWidth(), board->getHeight(), 3);

				if (player2 != NULL) {
					delete player2;
				}
				player2 = new Stick(board->getTopLeft().first, board->getTopLeft().second, board->getWidth(), board->getHeight(), 3);

				player1->setX( board->getTopLeft().first + board->getWidth() / 2 - player1->getsize()/2);
				player1->setY(board->getTopLeft().second + 1);

				player2->setX(board->getBotLeft().first + board->getWidth() / 2 - player2->getsize()/2);
				player2->setY(board->getBotLeft().second - 1);

				if (ball != NULL) {
					delete ball;
				}
				ball = new Ball(board->getTopLeft().first, board->getTopLeft().second, board->getWidth(), board->getHeight());

				Utils::clearScreen();

				board->showBoard();
				
				player1->spawn();
				player2->spawn();

				ball->spawn();

				this->tiepTuc = true;

				while (isContinue()) {
					
					this->curTime = GetTickCount64();

					if (this->curTime > this->startTime_player) {


						if (GetKeyState('A') & 0x8000) {
							player1->update(player1->getX() - 1, player1->getY());
						}

						if (GetKeyState('D') & 0x8000) {
							player1->update(player1->getX() + 1, player1->getY());
						}

						if (GetKeyState('J') & 0x8000) {
							player2->update(player2->getX() - 1, player2->getY());
						}

						if (GetKeyState('L') & 0x8000) {
							player2->update(player2->getX() + 1, player2->getY());
						}

						if (GetKeyState(VK_ESCAPE) & 0x8000) {
							this->tiepTuc = false;
						}

						

						this->startTime_player = this->curTime + this->tick_player;
					}

					if (this->curTime > this->startTime_ball) {

						ball->update();

						this->startTime_ball = this->curTime + this->tick_ball;

					}
					
				}

				Utils::showConsoleCursor(true);

				break;
			case 1:
				return;
		}

		
	}
}
bool Game::isContinue() {
	return tiepTuc;
}

void Game::moveRight_Player1() {
	player1->update(player1->getX() + 1, player1->getY());
}
void Game::moveLeft_Player1() {
	player1->update(player1->getX() - 1, player1->getY());
}

void Game::moveRight_Player2() {
	player2->update(player2->getX() + 1, player2->getY());
}
void Game::moveLeft_Player2() {
	player2->update(player2->getX() - 1, player2->getY());
}
