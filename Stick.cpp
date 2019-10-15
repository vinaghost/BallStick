#include "Stick.h"
#include "Graphic.h"



Stick::Stick(int left, int top, int width, int height, int size) : left(left), top(top), height(height), width(width), size(size) {
	this->spawned = false;

	x = left;
	y = top;
}

Stick::~Stick() {}

void Stick::setX(int x) {
	if (x > this->left && x + this->size < this->left + this->width) 
		this->x = x;
}

void Stick::setY(int y) {
	if (y > this->top && y < this->top + this->height)
		this->y = y;
}

void Stick::setSize(int size) {
	this->size = size;
}

int Stick::getX() {
	return this->x;
}

int Stick::getY() {
	return this->y;
}


int Stick::getsize() {
	return this->size;
}

void Stick::spawn() {
	// đã xuất hiện trên màn hình
	if (this->spawned) return;


	Graphic::drawStick(*this);
	this->spawned = true;
}

void Stick::despawn() {
	// đã biến mất khỏi màn hình
	if (!this->spawned) return;


	Graphic::deleteStick(*this);
	this->spawned = false;
}

void Stick::update(int x, int y) {
	this->despawn();
		
	this->setX(x);
	this->setY(y);

	this->spawn();
}