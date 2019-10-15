#include "Board.h"

#include "Graphic.h"

Board::Board(pair<int, int> topLeft, int width, int height) : topLeft(topLeft){
	this->botLeft = { this->topLeft.first, this->topLeft.second + height };

	this->topRight = { this->topLeft.first + width, this->topLeft.second };

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
	return this->getBotLeft().second - this->getTopLeft().second;
}

int Board::getWidth()
{
	return this->getTopRight().first - this->getTopLeft().first;
}

void Board::showBoard()
{
	Graphic::drawGameName();
	Graphic::drawBoard(*this);
}