#include "Ball.h"



Ball::Ball() : x(0), y(0) {}
Ball::Ball(int x, int y) : x(x), y(y) {}


Ball::~Ball() {}

void Ball::setX(int x) {
	this->x = x;
}

void Ball::setY(int y) {
	this->y = y;
}

int Ball::getX() {
	return this->x;
}

int Ball::getY() {
	return this->y;
}


