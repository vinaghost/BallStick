#include "Ball.h"

#include "Graphic.h"


// Khởi tạo tạo độ ban đầu của Ball
Ball::Ball() : Entity(), direction(BOT_LEFT) {}


void Ball::setDirect(Direction direction) {
	this->direction = direction;
}

Direction Ball::getDirect() { return this->direction; }

void Ball::reset() {
	despawn();
	x = b->getTopLeft().first + b->getWidth() / 2;
	y = b->getTopLeft().second + b->getHeight() / 2;
	spawn();
}
int Ball::update(Stick top, Stick bot) {
	
	// đụng biên trên
	if (this->y <= this->b->getTopLeft().second + 1) {
		return 3;
	}
	// đụng biên dưới
	if (this->y >= this->b->getBotLeft().second - 1) {
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
	else if (this->x <= this->b->getBotLeft().first + 1 ) {
		directNext = getNext(0);
		result = 1;
	}
	// đụng vào biên phải
	else if (this->x >= this->b->getBotRight().first - 1) {
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
			if (this->x <= this->b->getTopLeft().first + 1) {
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
			if (this->x >= this->b->getTopRight().second - 1) {
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
					if (this->x <= this->b->getTopLeft().first + 1)
						return BOT_RIGHT;

					return BOT_LEFT;

				case TOP_RIGHT:
					//góc phải
					if (this->x >= this->b->getTopRight().first - 1)
						return BOT_LEFT;

					return BOT_RIGHT;
			}
			break;
		case 3:
			//chạm stick dưới
			switch (this->direction) {
				case BOT_LEFT:
					//góc trái
					if (this->x <= this->b->getTopLeft().first + 1)
						return TOP_RIGHT;
					return TOP_LEFT;

				case BOT_RIGHT:
					//góc phải
					if (this->x >= this->b->getTopRight().first - 1)
						return TOP_LEFT;
					return TOP_RIGHT;
			}
			break;
	}
	return this->direction;
}

string Ball::getNameClass() {
	return "Ball";
}