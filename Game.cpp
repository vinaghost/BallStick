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
			moveLeft(b);
			break;
		case 'D':
			moveRight(b);
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

void Game::moveRight(Stick& b) {
	b.toRight_Duoi();
}
void Game::moveLeft(Stick& b) {
	a.toLeft_Duoi();
}