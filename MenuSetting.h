#pragma once
#include "Menu.h"
/*
Setting:
- đối kháng
- độ dài của thanh
- độ to của board
- tốc độ ball ban đầu
- tốc độ thanh
*/

enum itemSetting {
	MODE,
	LENGTH_STICK,
	SIZE_BOARD,
	SPEED_BALL,
	SPEED_STICK,
	SAVE
};

class MenuSetting :	public Menu {
private:
	
	char szSetting[SAVE][3][11] = {
		{ "PVP", "PVE" },
		{ "Ngan", "Trung binh", "Dai"},
		{ "Nho", "Trung binh",	"To" },
		{ "Cham", "Trung binh", "Nhanh"},
		{ "Cham", "Trung binh", "Nhanh"},

	};


	vector<int>itemSetting;

	/**
	* Thay đổi tên item
	*
	* @note xoá item có sẵn bằng 50 khoảng trắng sau đó 
	* in lại cái mới
	*
	* @param item - số thứ tự item
	* @param direction - 0 = tăng - 1 = giảm số thứ tự item
	*
	* @noreturn
	**/
	void changeItem(int item, int direction = 0);

	/**
	* Gọi khi nút qua trái được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	virtual void moveLeft();

	/**
	* Gọi khi nút qua phải được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	virtual void moveRight();

public:
	MenuSetting();
	
	/**
	* Trả về MODE được chọn ở menu setting 
	*
	* @note
	*
	* @return (int) 0 = PVP 1 = PVE
	**/
	int getMode();

	/**
	* Trả về LENGTH của STICK được chọn ở menu setting
	*
	* @note
	*
	* @return (int) 0 = ngắn 1 = trung bình 2 = dài
	**/
	int getLengthStick();

	/**
	* Trả về SIZE của BOARD được chọn ở menu setting
	*
	* @note
	*
	* @return (int) 0 = nhỏ 1 = trung bình 2 = to
	**/
	int getSizeBoard();

	/**
	* Trả về SPEED của BALL được chọn ở menu setting
	*
	* @note
	*
	* @return (int) 0 = chậm 1 = trung bình 2 = nhanh
	**/
	int getSpeedBall();

	/**
	* Trả về SPEED của STICK  được chọn ở menu setting
	*
	* @note
	*
	* @return (int) 0 = chậm 1 = trung bình 2 = nhanh
	**/
	int getSpeedStick();

	/**
	* Hiển thị menu ra Console
	*
	* @note hiển thị menu ra console sau khi xoá toàn màn hình
	* sau đó dùng phím w hoặc mũi tên lên để đi lên hay phím s
	* hoặc mũi tên xuống để điều khiển con trỏ đi xuống, dùng
	* phím enter để thay đổi item. Chọn Lưu để có thoát Menu.
	*
	*
	* @noreturn
	**/
	void show();

	//tắt getChoice ở menu Setting
	int getChoice() = delete;

};

