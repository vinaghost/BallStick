#include "Game.h"


Game::Game() {
	command = 0;
	tiepTuc = true;
	Stick a;
	while (isContinue()) {
		waitKeyBoard();
		switch (getCommand()) {
		case 27: // esc
			tiepTuc = false;
			break;
		case 'A':
			moveLeft(a);
			break;
		case 'D':
			moveRight(a);
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

void Game::moveRight(Stick& a) {
	a.toRight_Duoi();
}
void Game::moveLeft(Stick& a) {
	a.toLeft_Duoi();
}