#include "Menu.h"
#include <iostream>

int main() {

	Menu a;

	a.setTitle("Menu test");
	a.setCoordTitle(26, 8);
	a.setCoordItem(30, 10);
	a.addItem("New Game");
	a.addItem("exit");

	a.show();
	
	int choice = a.getChoice();

	std::cout << choice;
	getchar();
	return 0;
}