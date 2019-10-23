#include "Board.h"

#include "Graphic.h"

Board::Board() : topLeft({ 0, 0 }), topRight({ 0, 0 }), botLeft({ 0, 0 }), botRight({ 0, 0 }) {}

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
void Board::setBoard(int top, int left, int width, int height) {
	//trên trái
	this->topLeft = std::make_pair(top, left);
	
	//dưới trái
	this->botLeft = { this->topLeft.first, this->topLeft.second + height };

	//trên phải
	this->topRight = { this->topLeft.first + width, this->topLeft.second };

	//dưới phải
	this->botRight = { this->topRight.first, this->topRight.second + height };
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