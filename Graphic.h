#pragma once

#include "Ball.h"

#include "Stick.h"
class Graphic {
public:
	static void drawBall(Ball b);
	static void deleteBall(Ball b);
	/**
	* Hiện thị tên game lên màn hình console
	*
	* @note tên được tạo từ trang web  
	* http://www.kammerl.de/ascii/AsciiSignature.php 
	*
	*
	* @noreturn
	**/
	static void drawGameName();
	static void drawStick(int x, int y, int z);
	static void deleteStick(int x, int y, int z);
};

