#pragma once
#include "Board.h"

#include <string>
using namespace std;
class Entity
{
protected:
	Board* b;
	int x, y;
public:
	Entity();
	~Entity();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	virtual void update() = 0;
	virtual string getNameClass() = 0;
};

