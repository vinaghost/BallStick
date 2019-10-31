#pragma once
#include "Entity.h"
#include "Stick.h"

enum Direction {
	TOP_RIGHT,
	BOT_RIGHT,
	BOT_LEFT,
	TOP_LEFT
};

class Ball : public Entity {
private:
	Direction direction;

	/**
	* Trả về hướng tiếp theo của Ball khi va chạm
	*
	* @note trường hợp va chạm gồm 
	*	0 = va chạm biên trái
	*	1 = va chạm biên phải
	*	2 = va chạm Stick trên
	*	3 = va chạm Stick dưới
	*
	*
	* @param truongHop	trường hợp va chạm
	*
	* @return (Direction) Hướng tiếp theo của Ball
	**/
	Direction getNext(int truongHop);

public:
	Ball();

	/**
	* Gán hướng cho Ball
	*
	* @note enum Direction chỉ 8 hướng
	*
	* @param direction	hướng
	*
	* @noreturn
	**/
	void setDirect(Direction direction);
	

	/**
	* Khởi tạo lại Ball
	*
	* @note khởi tạo lại vị trí lúc bắt đầu game
	*
	*
	* @noreturn
	**/
	void reset();

	/**
	* Trả về hướng của Ball
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param y	tung độ
	*
	* @return (int) tung độ cho Ball
	**/
	Direction getDirect();

	/**
	* Thay đổi vị trí của Ball
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param top	Stick nằm trên
	* @param bot	Stick nằm dưới
	*
	* @return (int) 0 nếu ball không đụng gì 
	*				1 nếu ball đụng biên trái
	*				2 nếu ball đụng biên phải
	*				3 nếu ball đụng biên trên
	*				4 nếu ball đụng biên dưới
	*				5 nếu ball đụng stick trên
	*				6 nếu ball đụng stick dưới
	**/
	int update(Stick top, Stick boy);

	/**
	* Trả lại tên class
	*
	* @note 
	*
	*
	* @return (string) tên Class
	**/
	string getNameClass();
};

