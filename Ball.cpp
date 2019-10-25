#include "Ball.h"

#include "Graphic.h"

#include <cmath>
#include <cfloat>

// Khởi tạo tạo độ ban đầu của Ball, giới hạn di chuyển của Ball
Ball::Ball() : x(0), y(0), left(0), top(0), width(0), height(0), spawned(false), direction(BOT_LEFT) {}

void Ball::setX(int x) {
	// Xét điều kiện: tạo độ x nhập vào nằm bên trong bàn chơi
	if( x > this->left || x < this->left + this->width)
		this->x = x;
}

void Ball::setY(int y) {
	// Xét điều kiện: tạo độ y nhập vào nằm bên trong bàn chơi
	if (y > this->top || y < this->top + this->height)
		this->y = y;
}

void Ball::setDirect(Direction direction) {
	this->direction = direction;
}
void Ball::setBoard(int left, int top, int width, int height) {
	this->left = left > 0 ? left : 0;
	this->top = top > 0 ? top : 0;
	this->width = width > 0 ? width : 0;
	this->height = height > 0 ? height : 0;
}
int Ball::getX() { return this->x; }

int Ball::getY() { return this->y; }

Direction Ball::getDirect() { return this->direction; }

bool Ball::spawn() {

	Graphic::drawBall(*this);
	this->spawned = true;

	return this->spawned;
}
bool Ball::despawn() {
	Graphic::deleteBall(*this);
	this->spawned = false;
	return this->spawned;
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
	if ( top.getX() - 1  <= this->x  && this->x <= top.getX() + top.getSize() + 1 && top.getY() + 1 == this->y) {
		directNext = getNext(2);
		result = 5;
	}

	// đụng vào stick dưới
	// x nằm bên phải bot.getX && x nằm bên trái bot.getX + bot.getsize && y nằm bên trên 1 ô so với bot.getY
	else if (bot.getX() - 1 <= this->x && this->x <= bot.getX() + bot.getSize() + 1 && bot.getY() - 1 == this->y) {
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
		case TOP_RIGHT:
			x = 1;
			y = -1;
			break;
		case BOT_RIGHT:
			x = 1;
			y = 1;
			break;
		case BOT_LEFT:
			x = -1;
			y = 1;
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