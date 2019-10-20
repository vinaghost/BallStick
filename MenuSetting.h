﻿#pragma once
#include "Menu.h"

/*
Setting:
- đối kháng
- độ dài của thanh
- độ to của board
- tốc độ ball ban đầu
- tốc độ thanh
*/

enum {
	MODE,
	LENGTH_STICK,
	SIZE_BOARD,
	SPEED_BALL,
	SPEED_STICK
};

class MenuSetting :	public Menu {
private:
	
	const int saveItem = 5;

	char mode[2][4] = {
		"PVP",
		"PVE"
	};

	char length[3][11] = {
		"Ngan",
		"Trung binh",
		"Dai"
	};

	char size[3][11] = {
		"Nho",
		"Trung binh",
		"To"
	};

	const char speed[3][11] = {
		"Cham",
		"Trung binh",
		"Nhanh"
	};

	vector<int>itemSetting;

	/**
	* Thay đổi tên item
	*
	* @note
	*
	* @param item - số thứ tự item
	*
	* @noreturn
	**/
	void changeItem(int item);



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

