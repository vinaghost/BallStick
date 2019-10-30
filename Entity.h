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

	int color, color_background;

public:
	Entity();

	virtual string getNameClass() = 0;

	void setBoard(Board *b);

	virtual void setX(int x);

	virtual void setY(int y);

	void setColor(int color);

	void setBackgroundColor(int color_background);

	void setSize(int size);

	int getColor();

	int getBackgroundColor();

	int getX();

	int getY();

	int getSize();

	void spawn();

	void despawn();
};

