#pragma once

#include "Ball.h"
#include "Stick.h"

#include "Board.h"
#include "Utils.h"

#include "Entity.h"

class Graphic {
public:
	
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
	* @param board   đối tượng board để vẽ lên bảng
	* 
	* @noreturn
	**/
	static void drawBoard(Board board);

	//static void drawBall(Ball b);
	//static void deleteBall(Ball b);


	//static void drawStick(Stick s);
	//static void deleteStick(Stick s);

	static void draw(Entity* ent);
	static void remove(Entity* ent);

	static void drawPlayerWin();
	static void drawPlayerLose();
};

