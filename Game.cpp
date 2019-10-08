#include "Game.h"

#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <Windows.h>

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	command = 0;
	tiepTuc = true;
	
	b = new Ball(7, 10, 10);


	b->spawn();
	DWORD startTime, nextTime = 0;

	while (isContinue()) {
		waitKeyBoard();
		switch (getCommand()) {
			case 27: // esc
				tiepTuc = false;
				break;
			case 13: // enter
				return;
		}
		
		startTime = GetTickCount();

		if (startTime  > nextTime) {
			b->update();

			nextTime = startTime + 100;
		}
		
	}

	b->despawn();
}


Game::~Game() {
	delete b;
}

int Game::getCommand() {
	return command;
}
bool Game::isContinue() {
	return tiepTuc;
}

int Game::waitKeyBoard() {
	if (_kbhit()) {
		command = toupper(_getch());

		return command;
	}

	return 0;
}

void Game::moveRight() {

}
void Game::moveLeft() {

}