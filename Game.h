#pragma once

class Game {
private:
	int command;
	bool tiepTuc;
public:
	Game();
	~Game();


	int getCommand();
	bool isContinue();
	char waitKeyBoard();

	void moveRight();
	void moveLeft();
};

