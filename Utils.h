#pragma once
#include <windows.h>
#include "Stick.h"


class Utils {
public:

	/**
	* Không cho thay đổi kích thước console chương trình
	*
	* @note size của console: 900 x 700
	*
	* @noreturn
	**/
	static void fixConsoleWindow();

	/**
	* Di chuyển con trỏ
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	*
	* @param x		hoành độ
	* @param y		tung độ
	*
	* @noreturn
	**/
	static void gotoXY(int x, int y);

	/**
	* Trả về vị trí con trỏ hiện tại
	*
	* @note Toạ độ trong Console:	trục hoành hướng sang phải
	*								trục tung hướng xuống dưới
	*
	*
	* @return struct COORD { short x,  y} với x, y lần lượt là hoành và tung độ của con trỏ
	**/
	static COORD getCursor();

	/**
	* Xoá màn hình
	*
	* @note In liên tục 20 '\n' để có xoá màn hình,
	*		phải chạy hàm fixConsoleWindow() trước
	*		để hoạt động hiệu quả
	*
	* @noreturn
	*/
	static void clearScreen();
};

