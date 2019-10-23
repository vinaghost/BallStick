#pragma once

#include "Stick.h"

enum Direction {
	TOP_RIGHT,
	BOT_RIGHT,
	BOT_LEFT,
	TOP_LEFT
};

class Ball {
private:
	int x, y;

	int left, top;
	int width, height;

	bool spawned;

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
	* Gán hoành độ cho Ball
	* 
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param x	hoành độ
	*
	* @noreturn
	**/
	void setX(int x);

	/**
	* Gán tung độ cho Ball
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param y	tung độ
	*
	* @noreturn
	**/
	void setY(int y);

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
	* Cấu hình khung cho Ball
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
	* Trả về hoành độ cho Ball
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param x	hoành độ
	*
	* @return (int) hoành độ cho Ball
	**/
	int getX();

	/**
	* Trả về tung độ cho Ball
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param y	tung độ
	*
	* @return (int) tung độ cho Ball
	**/
	int getY();

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
	* Spawn Ball lên màn hình
	*
	* @note 
	*
	* @return (bool) tình trạng spawn của Ball
	**/
	bool spawn();

	/**
	* Despawn Ball khỏi màn hình
	*
	* @note
	*
	* @return (bool) tình trạng spawn của Ball
	**/
	bool despawn();

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

};

