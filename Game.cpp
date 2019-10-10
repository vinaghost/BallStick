#include "Game.h"


Game::Game() {
	command = 0;
	tiepTuc = true;
	
	this->loop();
}


Game::~Game() {
}

void Game::loop() {

	while (isContinue()) {
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
		}
	}
}
int Game::getCommand() {
	command = toupper(_getch());
	return command;
}
bool Game::isContinue() {
	return tiepTuc;
}

void Game::moveRight() {
}
void Game::moveLeft() {
}
