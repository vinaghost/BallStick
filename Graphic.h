#pragma once

#include "Ball.h"
#include "Board.h"

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
	/**
	* Hiện thị bảng game lên màn hình console
	*
	* @note 
	*
	*
	* @noreturn
	**/
	static void drawBoard(Board a);
};

