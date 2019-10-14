#include "Ball.h"

#include "Graphic.h"

#include <cmath>
#include <cfloat>


Ball::Ball(int left, int top, int width, int height) : left(left), top(top), width(width), height(height), x(left + width/2), y(top + height/2) {
	this->spawned = false;
	this->direction = BOT_LEFT;
}


Ball::~Ball() {}

void Ball::setX(int x) {
	this->x = x;
}

void Ball::setY(int y) {
	this->y = y;
}

void Ball::setDirect(Direction direction) {
	this->direction = direction;
}

int Ball::getX() {
	return this->x;
}

int Ball::getY() {
	return this->y;
}
Direction Ball::getDirect() {
	return this->direction;
}
bool Ball::spawn() {
	Graphic::drawBall(*this);
	this->spawned = true;
	return true;
}
bool Ball::despawn() {
	Graphic::deleteBall(*this);
	this->spawned = false;
	return false;
}
double Ball::update(double speed) {
	
	int x = 0;
	int y = 0;

	Direction directNext = getNext();
	this->setDirect(directNext);

	switch (directNext) {
		case TOP:
			y = -1;
			break;
		case TOP_RIGHT:
			x = 1;
			y = -1;
			break;
		case RIGHT:
			y = 1;
			break;
		case BOT_RIGHT:
			x = 1;
			y = 1;
			break;
		case BOT:
			y = 1;
			break;
		case BOT_LEFT:
			x = -1;
			y = 1;
			break;
		case LEFT:
			x = -1;
			break;
		case TOP_LEFT:
			x = -1;
			y = -1;
			break;
	}
	double dist = sqrt( (x) * (x) + (y) * (y) );


	despawn();

	this->setX(this->getX() + x);
	this->setY(this->getY() + y);

	spawn();

	return dist;
}


Direction Ball::getNext() {

	// chạm biên trái
	if (this->x <= this->left + 1) {
		switch (this->direction) {
			case BOT_LEFT: 
				return BOT_RIGHT;
				
			case TOP_LEFT:
				return TOP_RIGHT;
		}
	}

	// chạm biên phải
	if (this->x >= this->left + this->size + 20 - 1) {
		switch (this->direction) {
			case BOT_RIGHT:
				return BOT_LEFT;

			case TOP_RIGHT:
				return TOP_LEFT;
		}
	}

	//chạm biên trên 
	if (this->y <= this->top + 1) {
		switch (this->direction) {
			case TOP_LEFT:
				return BOT_LEFT;

			case TOP_RIGHT:
				return BOT_RIGHT;
		}
	}

	//chạm biên dưới
	if (this->y >= this->top + this->size - 1) {
		switch (this->direction) {
			case BOT_LEFT:
				return TOP_LEFT;

			case BOT_RIGHT:
				return TOP_RIGHT;
		}
	}

	return this->direction;
}