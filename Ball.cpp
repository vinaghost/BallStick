#include "Ball.h"

#include "Graphic.h"

#include <cmath>
#include <cfloat>

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

double Ball::update(int x, int y) {

	double dist = sqrt((x - this->getX()) * (x - this->getX()) + (y - this->getY()) * (y - this->getY()));

	if (dist < DBL_EPSILON) {
		return (double)0.0;
	}

	Graphic::deleteBall(*this);

	this->setX(x);
	this->setY(y);

	Graphic::drawBall(*this);

	return dist;
}


