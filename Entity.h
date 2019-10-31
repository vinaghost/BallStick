#pragma once
#include "Board.h"

#include <string>
using std::string;
class Entity
{
protected:
	Board* b;
	int x, y;
	int size;

	bool spawned;

	int color, color_background;

public:
	Entity();

	/**
	* Trả lại tên class
	*
	* @note
	*
	*
	* @noreturn (string) tên Class
	**/
	virtual string getNameClass() = 0;

	/**
	* Gán Board của Entity
	*
	* @note
	*
	*
	* @noreturn 
	**/
	void setBoard(Board *b);

	/**
	* Gán tọa độ x của Entity
	*
	* @note
	*
	*
	* @noreturn
	**/
	virtual void setX(int x);

	/**
	* Gán tọa độ y của Entity
	*
	* @note
	*
	*
	* @noreturn
	**/
	virtual void setY(int y);

	/**
	* Gán màu của Entity
	*
	* @note
	*
	*
	* @noreturn
	**/
	void setColor(int color);

	/**
	* Gán màu nền của Entity
	*
	* @note
	*
	*
	* @noreturn
	**/
	void setBackgroundColor(int color_background);

	/**
	* Gán độ dài của Entity
	*
	* @note
	*
	*
	* @noreturn
	**/
	void setSize(int size);

	/**
	* Trả lại màu của Entity
	*
	* @note
	*
	*
	* @return (int) color
	**/
	int getColor();

	/**
	* Trả lại màu nền của Entity
	*
	* @note
	*
	*
	* @return (int) color_background
	**/
	int getBackgroundColor();

	/**
	* Trả lại tọa độ x của Entity
	*
	* @note
	*
	*
	* @return (int) x
	**/
	int getX();

	/**
	* Trả lại tọa độ y của Entity
	*
	* @note
	*
	*
	* @return (int) y
	**/
	int getY();

	/**
	* Trả lại độ dài của Entity
	*
	* @note
	*
	*
	* @return (int) size
	**/
	int getSize();

	/**
	* Vẽ Entity
	*
	* @note
	*
	*
	* @noreturn
	**/
	void spawn();

	/**
	* Xóa Entity
	*
	* @note
	*
	*
	* @noreturn
	**/
	void despawn();
};

