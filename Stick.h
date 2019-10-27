#pragma once

#include <string>
using namespace std;

class Stick {
private:
	int x, y, size;

	int left, top;
	int width, height;

	bool spawned;

public:
	Stick();

	/**
	* Gán hoành độ cho điểm đầu của Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	*		Stick di chuyển ngang, không thay đổi y
	*
	* @param x	hoành độ
	* @noreturn
	**/
	void setX(int x);

	/**
	* Gán tung độ cho điểm đầu của Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	*		Stick di chuyển ngang, không thay đổi y
	*
	* @param y tung độ
	* @noreturn
	**/
	void setY(int y);

	/**
	* Gán độ dài cho Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	*		Stick sẽ dài ra về hướng bên phải màn hình
	*
	* @param size	độ dài
	* @noreturn
	**/
	void setSize(int size);

	/**
	* Cấu hình khung cho Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	*		Ball sẽ dài ra về hướng bên phải màn hình
	*
	* @param left	hoành độ gốc trái trên khung
	* @param top	tung độ gốc trái trên khung
	* @param width	độ dài khung
	* @param height	độ cao khung
	* @noreturn
	**/
	void setBoard(int left, int top, int width, int height);

	/**
	* Trả về hoành độ cho điểm đầu của Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	*		Stick di chuyển ngang, không thay đổi y
	*
	* @return (int) hoành độ cho Stick
	**/
	int getX();

	/**
	* Trả về tung độ cho điểm đầu của Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	*		Stick di chuyển ngang, không thay đổi y
	*
	* @return (int) tung độ cho Stick
	**/
	int getY();


	/**
	* Trả về độ dài của Stick
	*
	* @note Stick sẽ dài về hướng bên phải màn hình
	*
	* @return (int) độ dài cho Stick
	**/
	int getSize();

	/**
	* Hiển thị stick lên màn hình
	*
	* @note Thay đổi cách xuất hiện Stick ở Graphic.h
	*
	* @noreturn
	**/
	void spawn();

	/**
	* Xoá stick khỏi màn hình
	*
	* @note Thay đổi cách xoá Stick ở Graphic.h
	*
	* @noreturn
	**/
	void despawn();

	/**
	* Thay đổi vị trí của Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	*		Stick di chuyển ngang, không thay đổi y
	*
	* @param x  hoành độ mới của Stick
	*
	* @noreturn
	**/
	void update(int x);

	string getNameClass();
};
