#pragma once
#include "Entity.h"

class Stick : public Entity {
public:
	Stick();

	void setX(int x);

	string getNameClass();

	void update(int x);

};
