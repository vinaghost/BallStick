#include "MenuSetting.h"

#include "Utils.h"
#include "Graphic.h"

#include <iostream>

using std::cout;

MenuSetting::MenuSetting() : Menu() {
	
	this->setCoordTitle(34, 8);
	this->setTitle("Setting");

	this->setCoordItem(25, 10);
	this->addItem("Mode: ");
	itemSetting.push_back(0);
	this->addItem("Do dai cua thanh: ");
	itemSetting.push_back(1);
	this->addItem("Do to cua san choi: ");
	itemSetting.push_back(1);
	this->addItem("Toc do cua banh khi bat dau: ");
	itemSetting.push_back(1);
	this->addItem("Toc do cua thanh khi di chuyen: ");
	itemSetting.push_back(1);
	this->addItem("Luu");
	
}

int MenuSetting::getMode() { return itemSetting[MODE]; }

int MenuSetting::getLengthStick() { return itemSetting[LENGTH_STICK]; }

int MenuSetting::getSizeBoard(){ return itemSetting[SIZE_BOARD]; }

int MenuSetting::getSpeedBall(){ return itemSetting[SPEED_BALL]; }

int MenuSetting::getSpeedStick(){ return itemSetting[SPEED_STICK]; }

void MenuSetting::show() {

	Utils::clearScreen();
	Graphic::drawGameName();

	Utils::gotoXY(this->titleCoord.first, this->titleCoord.second);
	cout << this->title;

	int item = 0;

	//Mode
	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);
	cout << "\b[ ] " << this->itemName[item] << mode[this->itemSetting[item]];
	item++;
	//Độ dài của thanh
	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);
	cout << "\b[ ] " << this->itemName[item] << length[this->itemSetting[item]];
	item++;
	//Độ to của sân chơi
	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);
	cout << "\b[ ] " << this->itemName[item] << size[this->itemSetting[item]];
	item++;
	//Tốc độ của banh
	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);
	cout << "\b[ ] " << this->itemName[item] << speed[this->itemSetting[item]];
	item++;
	//tốc độ của thanh
	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);
	cout << "\b[ ] " << this->itemName[item] << speed[this->itemSetting[item]];
	item++;

	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);
	cout << "\b[ ] " << this->itemName[item];

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
				if (this->choice == saveItem) {
					return;
				}
				else {
					changeItem(this->choice);
				}
		}
	}
}

void MenuSetting::changeItem(int item) {
	
	itemSetting[item]++;
	if ((item == 0 && itemSetting[item] > 1) || (item != 0 && itemSetting[item] > 2)) itemSetting[item] = 0;
	
	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);
	
	for( int i = 0; i < 50; i++)	cout << " ";

	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);

	switch (item) {
		case MODE:

			cout << "\b[ ] " << this->itemName[item] << mode[this->itemSetting[item]];
			break;
		case LENGTH_STICK:
			cout << "\b[ ] " << this->itemName[item] << length[this->itemSetting[item]];
			break;
		case SIZE_BOARD:
			cout << "\b[ ] " << this->itemName[item] << size[this->itemSetting[item]];
			break;
		case SPEED_BALL:
			cout << "\b[ ] " << this->itemName[item] << speed[this->itemSetting[item]];
			break;
		case SPEED_STICK:
			cout << "\b[ ] " << this->itemName[item] << speed[this->itemSetting[item]];
			break;
	}

	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);
}