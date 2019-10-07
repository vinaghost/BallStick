#pragma once
class Ball {
	int x;
	int y;

public:
	Ball();
	Ball(int x, int y);
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
};

