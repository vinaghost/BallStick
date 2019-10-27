#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::setX(int x)
{
	this->x = x;
}

void Entity::setY(int y)
{
	this->y = y;
}

int Entity::getX()
{
	return this->x;
}

int Entity::getY()
{
	return this->y;
}
