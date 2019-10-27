#pragma once
#include "Board.h"

#include <string>
using std::string;
class Entity
{
protected:
	Board* b;
	int x, y;
	int size;

	bool spawned;

public:
	Entity();

	virtual string getNameClass() = 0;

	void setBoard(Board *b);

	virtual void setX(int x);

	virtual void setY(int y);

	void setSize(int size);

	int getX();

	int getY();

	int getSize();

	void spawn();

	void despawn();
};

