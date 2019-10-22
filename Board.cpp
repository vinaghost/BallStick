#include "Board.h"

#include "Graphic.h"

Board::Board(pair<int, int> topLeft, int width, int height) : topLeft(topLeft)  // Khởi tạo độ điểm trên bên trái và độ dài bàn chơi
{
	// Khởi tạo tọa độ điểm dưới bên trái
	this->botLeft = { this->topLeft.first, this->topLeft.second + height };

    // Khởi tạo tọa độ điểm trên bên phải
	this->topRight = { this->topLeft.first + width, this->topLeft.second };

	// Khởi tạo tọa độ điểm dưới bên phải
	this->botRight = { this->topRight.first, this->topRight.second + height};
}


Board::~Board() {
}

void Board::setTopleft(int x, int y)
{
	this->topLeft = std::make_pair(x, y);
}

void Board::setTopRight(int x, int y)
{
	this->topRight = std::make_pair(x, y);
}

void Board::setBotLeft(int x, int y)
{
	this->botLeft = std::make_pair(x, y);
}

void Board::setBotRight(int x, int y)
{
	this->botRight = std::make_pair(x, y);
}

pair<int, int> Board::getTopLeft()
{
	return this->topLeft;
}

pair<int, int> Board::getTopRight()
{
	return this->topRight;
}

pair<int, int> Board::getBotLeft()
{
	return this->botLeft;
}

pair<int, int> Board::getBotRight()
{
	return this->botRight;
}

int Board::getHeight()
{
	// Height = (tọa độ y của điểm dưới bên trái) - (tọa độ y của điển trên bên trái)
	return this->getBotLeft().second - this->getTopLeft().second;
}

int Board::getWidth()
{
	// Width = (tọa độ x của điểm trên bên phải) - (tọa độ x của điểm trên bên trái)
	return this->getTopRight().first - this->getTopLeft().first;
}

void Board::showBoard()
{
	// Hiển thị tên trò chơi
	Graphic::drawGameName();
	// Hiển thị bàn chơi
	Graphic::drawBoard(*this);
}