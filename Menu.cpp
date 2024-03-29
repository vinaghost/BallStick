﻿#include "Menu.h"

#include "Utils.h"
#include "Graphic.h"

#include <iostream>
#include <conio.h>

using std::cout;

Menu::Menu() : choice(0), command(0), itemCoord(0, 0) {
}


Menu::~Menu() {
}

void Menu::setCoordItem(int x, int y) {
	this->itemCoord = std::make_pair(x, y);
}
void Menu::setCoordTitle(int x, int y) {
	this->titleCoord = std::make_pair(x, y);
}
void Menu::setTitle(string title) {
	this->title = title;
}
int Menu::getChoice() {
	return choice;
}

char Menu::getCommand() {
	command = toupper(_getch());
	return command;
}

void Menu::addItem(string itemName) {
	this->itemName.push_back(itemName);
}

void Menu::show() {
	// In tên game
	Graphic::drawGameName();

	// Đến vị trí in tiêu đề
	Utils::gotoXY(this->titleCoord.first, this->titleCoord.second);
	// In tiêu đề
	cout << this->title;

	// In tên sự lựa chọn
	for (int item = 0; item < itemName.size(); item++) {
		Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);

		cout << "\b[ ] " << this->itemName[item];
	}

	this->choice = 0;	
	// Di chuyển đến vị trí lựa chọn đầu tiên
	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second);


	while (true) {
		switch (getCommand()) {
			case 'W':
				moveUp();
				break;
			case 'S':
				moveDown();
				break;
			case 13: 
				return;
		}
	}

}


void Menu::moveUp() {
	if (choice > 0) {
		choice--;
		Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + choice * 2);
	}
}

void Menu::moveDown() {
	if (choice < this->itemName.size() - 1 ) {
		choice++;
		Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + choice * 2);
	}
}

void Menu::moveLeft() {}

void Menu::moveRight() {}