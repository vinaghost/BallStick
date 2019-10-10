#pragma once
#include <string>
#include <vector>
#include <utility>

using std::string;
using std::vector;
using std::pair;

class Menu {
protected:
	int choice;
	char command;

	string title;
	pair <int, int> titleCoord;

	vector<string> itemName;
	pair <int, int> itemCoord;
	
	/**
	* Trả về nút được bấm
	*
	* @note
	*
	*
	* @return (char) mã ASCII của nút đã được chuyển thành in hoa
	**/
	char getCommand();

	/**
	* Gọi khi nút lên trên được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	void moveUp();

	/**
	* Gọi khi nút xuống dưới được bấm
	*
	* @note
	*
	*
	* @noreturn
	**/
	void moveDown();


public:
	
	Menu();
	virtual ~Menu();

	/**
	* Thiết lập tiêu đề của menu
	*
	* @note
	*
	* @param title - tiêu đề
	*
	* @noreturn
	**/
	void setTitle(string title);

	/**
	* Thiết lập toạ độ gốc của tiêu đề menu
	*
	* @note
	*
	* @param x - hoành độ
	* @param y - tung độ
	*
	* @noreturn
	**/
	void setCoordTitle(int x, int y);

	/**
	* Thiết lập toạ độ gốc của các item trong menu
	*
	* @note
	*
	* @param x - hoành độ
	* @param y - tung độ
	*
	* @noreturn
	**/
	void setCoordItem(int x, int y);

	/**
	* Thêm item vào menu
	*
	* @note
	*
	* @param itemName - tên của item
	*
	*
	* @noreturn
	**/
	void addItem(string itemName);

	/**
	* Hiển thị menu ra Console
	*
	* @note hiển thị menu ra console sau khi xoá toàn màn hình
	* sau đó dùng phím w hoặc mũi tên lên để đi lên hay phím s
	* hoặc mũi tên xuống để điều khiển con trỏ đi xuống, dùng 
	* phím enter để chọn item
	*
	*
	* @noreturn
	**/
	void show();

	/**
	* Trả về lựa chọn item
	*
	* @note
	*
	*
	* @return (int) item được chọn
	**/
	int getChoice();

};

