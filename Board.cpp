#include "Board.h"

#include "Graphic.h"

Board::Board()
{
	this->topLeft.first = 0;
	this->topLeft.second = 10;
	this->topRight.first = 40;
	this->topRight.second = 10;
	this->botLeft.first = 0;
	this->botLeft.second = 26;
	this->botRight.first = 40;
	this->botRight.second = 26;
}


Board::~Board()
{
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

void Board::setPlace(int x1, int y1, int x2, int y2, int x3, int y3)
{
	this->setTopleft(x1,y1);
	this->setTopRight(x2,y2);
	this->setBotLeft(x3,y3);
	this->setBotRight(x2,y3);
}

void Board::showBoard()
{
	Graphic::drawGameName();
	Graphic::drawBoard(*this);
}