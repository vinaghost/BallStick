#include "Stick.h"
#include "Graphic.h"

// Hàm khởi tạo điểm đầu của Stick và các giá trị về kích thước Stick, giới hạn di chuyển của Stick(giới hạn bàn chơi).
Stick::Stick(int left, int top, int width, int height, int size) : left(left), top(top), height(height), width(width), size(size) 
{
	//Xét sự tồn tại của Stick.
	this->spawned = false;
	
	//Khởi tạo tọa độ điểm đầu của Stick(x,y).
	x = left;
	y = top;
}

Stick::~Stick() {}

void Stick::setX(int x) {
	//Xét điều kiện: tọa độ x được nhập vào phải nằm trong chiều rộng của bàn và độ dài Stick lúc này không vượt qua chiều dài của bàn.
	if (x > this->left && x + this->size < this->left + this->width) 
		this->x = x;
}

void Stick::setY(int y) {
	//Xét điều kiện: tọa độ y được nhập vào phải nằm trong chiều dài của bàn.
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

void Stick::update(int x, int y) {
	this->despawn();
		
	this->setX(x);
	this->setY(y);

	this->spawn();
}