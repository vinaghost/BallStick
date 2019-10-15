#include "Game.h"
#include "Utils.h"
#include "Graphic.h"
#include "Menu.h"

#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <Windows.h>

Game::Game() {
	this->command = 0;
	this->tiepTuc = true;
	
	menuMain.addItem("Start");
	menuMain.addItem("Exit");

	menuMain.setCoordItem(20, 10);

	this->loop();
}


Game::~Game() {
	delete ball;

	delete player1;
	delete player2;
}

void Game::loop() {

	int choice;
	DWORD startTime = GetTickCount() + 200;
	DWORD curTime;

	while (true) {
		Utils::clearScreen();
		menuMain.show();
		choice = menuMain.getChoice();

		switch (choice) {
			case 0:

				player1 = new Stick(board.getBotLeft().second - board.getTopLeft().second, board.getTopRight().first - board.getTopLeft().first);
				player2 = new Stick(board.getBotLeft().second - board.getTopLeft().second, board.getTopRight().first - board.getTopLeft().first);

				player1->setX(board.getTopLeft().first);
				player1->setY(board.getTopLeft().second + 1);
				player2->setX(board.getBotLeft().first);
				player2->setY(board.getBotLeft().second - 1);

				ball = new Ball(board.getTopLeft().first, board.getTopLeft().second, 20, 30);
				Utils::clearScreen();

				board.showBoard();

				Graphic::drawStick(*player1);
				Graphic::drawStick(*player2);

				ball->spawn();
				
				getchar();

				while (isContinue()) {
					
					switch (getCommand()) {
						case 'A':
							moveLeft_Player1();
							break;
						case 'D':
							moveLeft_Player1();
							break;
						case 'J':
							moveLeft_Player2();
							break;
						case 'L':
							moveLeft_Player2();
							break;
						case 27:  //esc
							this->tiepTuc = false;
							break;
					}

					curTime = GetTickCount();

					if (startTime > curTime) {
						startTime = curTime + 200;
						ball->update();
					}

					
				}


				break;
			case 1:
				return;
		}

		
	}
}
int Game::getCommand() {
	if (_kbhit()) {
		command = toupper(_getch());
		return command;
	}

	return 0;
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
