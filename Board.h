#pragma once

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
	* Trả lại chiều dài của bảng game
	*
	* @note
	*
	*
	* @return (int) chiều dài
	**/
	int getHeight();
	/**
	* Trả lại chiều rộng của bảng game
	*
	* @note
	*
	*
	* @return (int) chiều rộng
	**/
	int getWidth();
	/**
	* Khỏi tạo lại tọa độ các điểm của Board 
	*
	* @note (x1, x2) tọa độ topLeft
	*       (x2, y2) tọa độ topRight
	*       (x3, y3) tọa độ botLeft
	*
	*
	* @noreturn
	**/
	void setPlace(int x1, int y1, int x2, int y2, int x3, int y3);
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

