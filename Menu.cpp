#include "Menu.h"

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

	Utils::clearScreen();
	Graphic::drawGameName();

	Utils::gotoXY(this->titleCoord.first, this->titleCoord.second);
	cout << this->title;

	for (int item = 0; item < itemName.size(); item++) {
		Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);

		cout << "\b[ ] " << this->itemName[item];
	}

	this->choice = 0;		
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
	if (choice < this->itemName.size() ) {
		choice++;
		Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + choice * 2);
	}
}