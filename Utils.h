#pragma once
#include <windows.h>
#include "Stick.h"


class Utils {
public:

	/**
	* Không cho thay đổi kích thước console chương trình
	*
	* @note size của console: 630 x 700
	*
	* @noreturn
	**/
	static void fixConsoleWindow();


	/**
	* Hiện/Ẩn con trỏ trên màn hình console
	*
	* @note size của console: 630 x 700
	*
	* @param show   true = hiện con trỏ, false = ẩn con trỏ
	* 
	* @noreturn
	**/	
	static void showConsoleCursor(bool show);


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
	* Thiết lập màu cho chữ được in ra màn hình console
	*
	* @note Chú ý cần phải thiết lập lại chữ màu trắng nền đen sau khi
	* đã in ra chữ nhằm tránh trường hợp phần sau có màu không theo ý muốn
	*        0 = đen
	*        1 = xanh dương đậm
	*        2 = xanh lá
	*        3 = xanh dương nhạt
	*        4 = đỏ
	*        5 = tím
	*        6 = vàng đất
	*        7 = trắng xám
	*        8 = xám
	*        9 = xanh dương giữa 1 và 3
	*        10 = xanh lá mạ
	*        11 = xanh dương nhạt hơn xanh dương nhạt
	*        12 = đỏ nhạt
	*        13 = tím nhạt
	*        14 = vàng nhạt
	*        15 = trắng
	* @param color            màu của chữ
	* @param colorBacckground màu của nền trong dòng chữ xuất hiện ( không phải 
	*						  toàn bộ nền của console)
	*
	* @noreturn
	*/
	static void setColorText(int color = 15, int colorBackground = 0);

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

	/**
	* Phát file nhạc
	*
	* @note Chỉ file đuôi wav
	*
	* @param fileName tên file name
	* @noreturn
	*/
	static void playSound(const char fileName[], bool loop = false);
};

