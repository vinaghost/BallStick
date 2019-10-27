#include "Entity.h"

#include "Graphic.h"


Entity::Entity() : b(NULL), x(0), y(0), size(0), spawned(false) {}

void Entity::setBoard(Board *b) {
	if (b != NULL) {
		this->b = b;
	}
}

void Entity::setX(int x) {
	if (x > this->b->getTopLeft().first && x < this->b->getTopRight().first) {
		this->x = x;
	}
}

void Entity::setY(int y) {
	if (y > this->b->getTopLeft().second && y < this->b->getBotLeft().second) {
		this->y = y;
	}
}

void Entity::setSize(int size) {
	if (size > 0) {
		this->size = size;
	}
}

int Entity::getX() {
	return this->x;
}

int Entity::getY() {
	return this->y;
}

int Entity::getSize() {
	return this->size;
}

void Entity::spawn() {
	// đã xuất hiện trên màn hình.
	if (this->spawned) return;

	// Ngược lại, vẽ và xác nhận Entity đã xuất hiện.
	Graphic::draw(this);
	this->spawned = true;
}

void Entity::despawn() {
	// đã biến mất khỏi màn hình.
	if (!this->spawned) return;

	// Ngược lại, xóa và xác nhận Entity đã biến mất.
	Graphic::remove(this);
	this->spawned = false;
}
