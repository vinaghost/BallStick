#include "Game.h"

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

int Game::waitKeyBoard() {
	command = toupper(_getch());
	return command;
}

void Game::moveRight() {
	a.update(2);
}
void Game::moveLeft() {
	a.update(1);
}