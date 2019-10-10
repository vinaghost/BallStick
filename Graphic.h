#pragma once

#include "Ball.h"

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
};

