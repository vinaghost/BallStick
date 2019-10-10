#pragma once

enum Direction {
	NONE,
	TOP,
	TOP_RIGHT,
	RIGHT,
	BOT_RIGHT,
	BOT,
	BOT_LEFT,
	LEFT,
	TOP_LEFT
};

class Ball {
private:
	int x;
	int y;

	int top, left;
	int size;

	bool spawned;

	Direction direction;

	/**
	* Trả về hướng tiếp theo của Ball khi va chạm
	*
	* @note 
	*
	* @return (Direction) Hướng tiếp theo của Ball
	**/
	Direction getNext();

public:
	Ball() = delete;
	Ball(int top, int left, int size);
	~Ball();

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
	* @param speed tốc độ Ball
	*
	* @return (double) khoảng cách trước và sau khi update Ball
	**/
	double update(double speed = 1.0);

};

