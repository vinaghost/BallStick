﻿#include "Stick.h"
#include "Graphic.h"

Stick::Stick() : x(0), y(0), size(0), left(0), top(0), width(0), height(0), spawned(false) {}

void Stick::setX(int x) {
	//Xét điều kiện: tọa độ x được nhập vào phải nằm trong chiều rộng của bàn và độ dài Stick lúc này không vượt qua chiều dài của bàn.
	if (x > this->left && x + this->size < this->left + this->width) 
		this->x = x;
}
void Stick::setY(int y) {
	// Xét điều kiện: tạo độ y nhập vào nằm bên trong bàn chơi
	if (y > this->top || y < this->top + this->height)
		this->y = y;
}

void Stick::setSize(int size) {	this->size = size > 0 ? size : 0; }

void Stick::setBoard(int left, int top, int width, int height) {
	this->left = left > 0 ? left : 0;
	this->top = top > 0 ? top : 0;
	this->width = width > 0 ? width : 0;
	this->height = height > 0 ? height : 0;
}
int Stick::getX() {	return this->x; }

int Stick::getY() {	return this->y; }

int Stick::getSize() { return this->size; }

void Stick::spawn() {
	// đã xuất hiện trên màn hình.
	if (this->spawned) return;

	// Ngược lại, vẽ Stick và xác nhận Stick đã xuất hiện.
	Graphic::drawStick(*this);
	this->spawned = true;
}

void Stick::despawn() {
	// đã biến mất khỏi màn hình.
	if (!this->spawned) return;

	// Ngược lại, xóa Stick và xác nhận Stick đã biến mất.
	Graphic::deleteStick(*this);
	this->spawned = false;
}

void Stick::update(int x) {
	this->despawn();
		
	this->setX(x);

	this->spawn();
}

string Stick::getNameClass()
{
	return "Stick";
}