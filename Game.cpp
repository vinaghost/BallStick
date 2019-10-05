#include "Game.h"

#include <stdio.h>
#include <ctype.h>
#include <conio.h>


Game::Game() {
	command = 0;
	tiepTuc = true;

	while (isContinue()) {
		waitKeyBoard();
		switch (getCommand()) {
			case 27: // esc
				tiepTuc = false;
				break;
			case 'A':
				moveLeft();
				break;
			case 'D':
				moveRight();
				break;
			case 13: // enter
				return;
		}
	}
}


Game::~Game() {
}

int Game::getCommand() {
	return command;
}
bool Game::isContinue() {
	return tiepTuc;
}

char Game::waitKeyBoard() {
	command = toupper(_getch());
	return command;
}

void Game::moveRight() {

}
void Game::moveLeft() {

}