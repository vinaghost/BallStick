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
	if( x > this->left || x < this->left + this->width)
		this->x = x;
}

void Ball::setY(int y) {
	if (y > this->top || y < this->top + this->height)
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
int Ball::update(Stick top, Stick bot) {
	
	// đụng biên trên
	if (this->y <= this->top + 1) {
		return 3;
	}
	// đụng biên dưới
	if (this->y >= this->top + this->height - 1) {
		return 4;
	}

	int x = 0;
	int y = 0;

	int result;
	Direction directNext;

	// đụng vào stick trên
	// x nằm bên phải top.getX && x nằm bên trái top.getX + top.getsize && y nằm bên dưới 1 ô so với top.getY
	if ( top.getX() <= this->x  && this->x <= top.getX() + top.getsize()  && top.getY() + 1 == this->y) {
		directNext = getNext(2);
		result = 5;
	}

	// đụng vào stick dưới
	// x nằm bên phải bot.getX && x nằm bên trái bot.getX + bot.getsize && y nằm bên trên 1 ô so với bot.getY
	else if (bot.getX() <= this->x && this->x <= bot.getX() + bot.getsize() && bot.getY() - 1 == this->y) {
		directNext = getNext(3);
		result = 6;
	}
	// đụng vào biên trái
	else if (this->x <= this->left + 1 ) {
		directNext = getNext(0);
		result = 1;
	}
	// đụng vào biên phải
	else if (this->x >= this->left + this->width - 1) {
		directNext = getNext(1);
		result = 2;
	}
	else {
		directNext = this->direction;
		result = 0;
	}
	

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


	despawn();

	this->setX(this->getX() + x);
	this->setY(this->getY() + y);

	spawn();

	return result ;
}


Direction Ball::getNext(int truongHop) {

	switch (truongHop) {
		case 0:
			// chạm biên trái
			if (this->x <= this->left + 1) {
				switch (this->direction) {
					case BOT_LEFT:
						return BOT_RIGHT;

					case TOP_LEFT:
						return TOP_RIGHT;
				}
			}
			break;
		case 1:
			// chạm biên phải
			if (this->x >= this->left + this->width - 1) {
				switch (this->direction) {
					case BOT_RIGHT:
						return BOT_LEFT;

					case TOP_RIGHT:
						return TOP_LEFT;
				}
			}
			break;
		case 2:
			//chạm stick trên
			switch (this->direction) {
				case TOP_LEFT:
					//góc trái
					if (this->x <= this->left + 1) 
						return BOT_RIGHT;

					return BOT_LEFT;

				case TOP_RIGHT:
					//góc phải
					if (this->x >= this->left + this->width - 1)
						return BOT_LEFT;

					return BOT_RIGHT;
			}
			break;
		case 3:
			//chạm stick dưới
			switch (this->direction) {
				case BOT_LEFT:
					//góc trái
					if (this->x <= this->left + 1)
						return TOP_RIGHT;
					return TOP_LEFT;

				case BOT_RIGHT:
					//góc phải
					if (this->x >= this->left + this->width - 1)
						return TOP_LEFT;
					return TOP_RIGHT;
			}
			break;
	}
	return this->direction;
}