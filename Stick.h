#pragma once

class Stick {
private:
	int x, y, size;

	int left, top;
	int width, height;

	bool spawned;

public:
	Stick() = delete;
	Stick(int left, int top, int width, int height, int size);
	~Stick();

	/**
	* Gán hoành độ cho điểm đầu của Stick
	*
	* @note  Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param x	hoành độ
	* @noreturn
	**/
	void setX(int x);

	/**
	* Gán tung độ cho điểm đầu của Stick
	*
	* @note  Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param y	tung độ
	*
	* @noreturn
	**/
	void setY(int y);

	/**
	* Gán độ dài cho Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	*		Stick sẽ dài ra về hướng bên phải màn hình
	* @param size	độ dài
	* @noreturn
	**/
	void setSize(int size);

	/**
	* Trả về hoành độ cho điểm đầu của Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	*
	* @return (int) hoành độ cho Stick
	**/
	int getX();

	/**
	* Trả về tung độ cho điểm đầu của Stick
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
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
	int getsize();

	/**
	* Hiển thị stick lên màn hình
	*
	* @note 
	*
	* @noreturn
	**/
	void spawn();

	/**
	* Xoá stick khỏi màn hình
	*
	* @note
	*
	* @noreturn
	**/
	void despawn();

	/**
	* Thay đổi vị trí của Stick
	*
	* @note  Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	* @param x  hoành độ mới của Stick
	* @param y	tung độ mới của Stick
	* @noreturn
	**/
	void update(int x, int y);
};
