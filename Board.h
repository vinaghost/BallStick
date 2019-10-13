#pragma once
#include "Graphic.h"
#include "Utils.h"
#include <utility>

using std::pair;
class Board
{
private:
	pair<int, int> topLeft ;
	pair<int, int> botLeft ;
	pair<int, int> topRight;
	pair<int, int> botRight;
public:
	Board();
	~Board();
	/**
	* Tạo tọa độ điểm phía trên bên trái của bảng game
	*
	* @note
	*
	*
	* @noreturn
	**/
	void setTopleft(int x, int y);
	/**
	* Tạo tọa độ điểm phía trên bên phải của bảng game
	*
	* @note
	*
	*
	* @noreturn
	**/
	void setTopRight(int x, int y);
	/**
	* Tạo tọa độ điểm phía dưới bên trái của bảng game
	*
	* @note
	*
	*
	* @noreturn
	**/
	void setBotLeft(int x, int y);
	/**
	* Tạo tọa độ điểm phía dưới bên phải của bảng game
	*
	* @note
	*
	*
	* @noreturn
	**/
	void setBotRight(int x, int y);
	/**
	* Trả lại tọa độ điểm phía trên bên trái của bảng game
	*
	* @note
	*
	*
	* @return (int, int) cặp tọa độ điểm phía trên bên trái
	**/
	pair<int, int> getTopLeft();
	/**
	* Trả lại tọa độ điểm phía trên bên phải của bảng game
	*
	* @note
	*
	*
	* @return (int, int) cặp tọa độ điểm phía trên bên phải
	**/
	pair<int, int> getTopRight();
	/**
	* Trả lại tọa độ điểm phía dươi bên trái của bảng game
	*
	* @note
	*
	*
	* @return (int, int) cặp tọa độ điểm phía dưới bên trái
	**/
	pair<int, int> getBotLeft();
	/**
	* Trả lại tọa độ điểm phía dưới bên phải của bảng game
	*
	* @note
	*
	*
	* @return (int, int) cặp tọa độ điểm phía dưới bên phải
	**/
	pair<int, int> getBotRight();
	/**
	* Tạo vị trí của bảng game
	*
	* @note
	*
	*
	* @noreturn
	**/
	void setPlace();
	/**
	* Hiện bảng game lên màn hình console 
	*
	* @note
	*
	*
	* @noreturn
	**/
	void showBoard();
};

