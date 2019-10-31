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
	//giá trị mặc định
	itemSetting.push_back(0);

	this->addItem("Do dai cua thanh: ");
	//giá trị mặc định
	itemSetting.push_back(1);

	this->addItem("Do to cua san choi: ");
	//giá trị mặc định
	itemSetting.push_back(1);

	this->addItem("Toc do cua banh khi bat dau: ");
	//giá trị mặc định
	itemSetting.push_back(1);
	this->addItem("Toc do cua thanh khi di chuyen: ");
	//giá trị mặc định
	itemSetting.push_back(1);

	this->addItem("Luu");
	
}

int MenuSetting::getMode() { return itemSetting[MODE]; }

int MenuSetting::getLengthStick() { return itemSetting[LENGTH_STICK]; }

int MenuSetting::getSizeBoard(){ return itemSetting[SIZE_BOARD]; }

int MenuSetting::getSpeedBall(){ return itemSetting[SPEED_BALL]; }

int MenuSetting::getSpeedStick(){ return itemSetting[SPEED_STICK]; }

void MenuSetting::show() {
	// xoá màn hình
	Utils::clearScreen();
	
	//hiện tên game
	Graphic::drawGameName();

	//hiện tên menu
	Utils::gotoXY(this->titleCoord.first, this->titleCoord.second);
	cout << this->title;
	int item = 0;
	for (item; item < SAVE; item++) {
		Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);

		//có thể chuyển qua bên trái
		if (this->itemSetting[item] != 0) {
			//xanh
			Utils::setColorText(2);
		}
		else {
			//đỏ
			Utils::setColorText(4);
		}
		cout << "\b< ";

		//có thể chuyển qua bên phải
		if (!((item == MODE && itemSetting[item] == 1) || (item != MODE && itemSetting[item] == 2))) {
			//xanh
			Utils::setColorText(2);
		}
		else {
			//đỏ
			Utils::setColorText(4);
		}
		cout << "> ";
		Utils::setColorText();

		cout << this->itemName[item];

		//xanh dương
		Utils::setColorText(1);
		cout << szSetting[item][this->itemSetting[item]];
		Utils::setColorText();

	}
	
	//hiện nút lưu
	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + SAVE * 2);
	cout << "\b[ ] " << this->itemName[SAVE];

	this->choice = 0;
	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second);


	while (true) {
		switch (getCommand()) {
			case 'W':
			case 'I':
				moveUp();
				break;
			case 'S':
			case 'K':
				moveDown();
				break;
			case 'A':
			case 'J':
				moveLeft();
				break;
			case 'D':
			case 'L':
				moveRight();
				break;
			case 13: //enter
				if (this->choice == SAVE) {
					return;
				}
		}
	}
}

void MenuSetting::changeItem(int item, int direction) {
	
	//di chuyển giảm nhưng không phải phần tử đầu
	if (direction == 1 && itemSetting[item] != 0) {
		itemSetting[item]--;
	}
	//di chuyển tăng nhưng không phải phần tử cuối
	//mode chỉ có 2 trong khi còn lại thì có 3
	else if (direction == 0 && !((item == MODE && itemSetting[item] == 1) || (item != MODE && itemSetting[item] == 2))) {
		itemSetting[item]++;
	}
	
	//đi tới toạ độ của phần tử
	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);
	
	//xoá nó đi
	for( int i = 0; i < 50; i++)	cout << " ";

	//quay lại chỗ cũ vì khi xoá con trỏ đã dịch chuyển đi vị trí khác
	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);

	// in lại phần tử
	//có thể chuyển qua bên trái
	if (this->itemSetting[item] != 0) {
		//xanh
		Utils::setColorText(2);
	}
	else {
		//đỏ
		Utils::setColorText(4);
	}
	cout << "\b< ";

	//có thể chuyển qua bên phải
	if (!((item == MODE && itemSetting[item] == 1) || (item != MODE && itemSetting[item] == 2))) {
		//xanh
		Utils::setColorText(2);
	}
	else {
		//đỏ
		Utils::setColorText(4);
	}
	cout << "> ";
	Utils::setColorText();

	cout << this->itemName[item];

	//xanh dương
	Utils::setColorText(1);
	cout << szSetting[item][this->itemSetting[item]];
	Utils::setColorText();

	//quay con trỏ về vị trí cũ vì khi in đã làm thay đổi vị trí
	Utils::gotoXY(this->itemCoord.first, this->itemCoord.second + item * 2);
}

void MenuSetting::moveLeft() {
	//thay đổi phần tử giảm
	changeItem(this->choice, 1);
}

void MenuSetting::moveRight() {
	//thay đổi phần tử tăng
	changeItem(this->choice, 0);
}
