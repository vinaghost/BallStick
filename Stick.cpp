#include "Stick.h"
#include "Graphic.h"

Stick::Stick() : Entity() {}

void Stick::setX(int x) {
	//Xét điều kiện: tọa độ x được nhập vào phải nằm trong chiều rộng của bàn và độ dài Stick lúc này không vượt qua chiều dài của bàn.
	if (x > this->b->getTopLeft().first && x + this->size <= this->b->getTopRight().first) {
		this->x = x;
	}
}

void Stick::update(int x) {
	this->despawn();
		
	this->setX(x);

	this->spawn();
}

string Stick::getNameClass() {
	return "Stick";
}