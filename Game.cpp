#include "Game.h"
#include "Utils.h"
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
	delete b;
}

void Game::loop() {

	int choice;

	while (isContinue()) {

		menuMain.show();
		choice = menuMain.getChoice();

		switch (choice) {
			case 0:
				break;
			case 1:
				this->tiepTuc = false;
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
