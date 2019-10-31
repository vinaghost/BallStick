#pragma once
#include "Entity.h"

class Stick : public Entity {
public:
	Stick();

	/**
	* Gán vị trí điểm đầu cho stick
	*
	* @note 
	*
	*
	* @noreturn
	**/
	void setX(int x);

	/**
	* Trả lại tên class
	*
	* @note
	*
	*
	* @return (string) tên Class
	**/
	string getNameClass();

	/**
	* Thay đổi Stick
	*
	* @note khởi tạo lại Stick bằng cách xóa, khởi tạo lại điểm đầu và vẽ lại Stick
	*
	*
	* @noreturn
	**/
	void update(int x);

};
