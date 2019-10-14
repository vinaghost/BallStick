#include "Board.h"

#include "Graphic.h"

Board::Board()
{
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

void Board::setPlace()
{
	this->setTopleft(10,10);
	this->setTopRight(40,10);
	this->setBotLeft(10,20);
	this->setBotRight(40,20);
}

void Board::showBoard()
{
	
	Graphic::drawBoard(*this);
	Utils::gotoXY(0, 0);
	Graphic::drawGameName();
}