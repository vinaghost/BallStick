#include "Graphic.h"
#include "Utils.h"

#include <cstdio>
#include <iostream>

using std::cout;

void Graphic::drawGameName() {
	Utils::setColorText(11, 0);
	cout << "\t\t\t _____\n";
	cout << "\t\t\t|  __ \\ \n";
	cout << "\t\t\t| |__) |__  _ __   __ _\n";
	cout << "\t\t\t|  ___/ _ \\| '_ \\ / _` |\n";
	cout << "\t\t\t| |   |(_) | | | | (_| |\n";
	cout << "\t\t\t|_|   \\___/|_| |_|\\__, |\n";
	cout << "\t\t\t                   __/ |\n";
	cout << "\t\t\t                  |___/\n";
	Utils::setColorText(15, 0);
}
/* void Graphic::drawBall(Ball b) {
	// Di chuyển đến tọa độ cần vẽ 
	Utils::gotoXY(b.getX(), b.getY());

	//màu đỏ
	Utils::setColorText(10, 0);

	// Vẽ Ball
	putchar('O');

	//màu trắng
	Utils::setColorText(15, 0);
}
void Graphic::deleteBall(Ball b) {
	// Di chuyển đến tọa độ cần xóa 
	Utils::gotoXY(b.getX(), b.getY());
	// Xóa Ball
	putchar(' ');
}

void Graphic::drawStick(Stick s) {
	
}

void Graphic::deleteStick(Stick s) {
	// Di chuyển đến tọa độ cần xóa
	Utils::gotoXY(s.getX(), s.getY());
	// Xóa Stick
	for (int i = 0; i <= s.getSize(); i++) {
		putchar(' ');
	}
}
*/

void Graphic::draw(Entity* ent) {
	//Tới vị trí
	Utils::gotoXY(ent->getX(), ent->getY());

	// Vẽ Stick
	if (ent->getNameClass() == "Stick") {
		//màu xanh dương
		Utils::setColorText(3, 0);
		for (int i = 0; i < ent->getSize(); i++) {
			putchar('*');
		}
	}
	// Vẽ Ball
	else if (ent->getNameClass() == "Ball") {
		//màu đỏ
		Utils::setColorText(10, 0);

		putchar('O');
	}
	//màu trắng
	Utils::setColorText(15, 0);
}

void Graphic::remove(Entity* ent) {
	//Tới vị trí
	Utils::gotoXY(ent->getX(), ent->getY());

	// Xoá Stick
	if (ent->getNameClass() == "Stick") {

		for (int i = 0; i < ent->getSize(); i++) {
			putchar(' ');
		}
	}
	// Xoá Ball
	else if (ent->getNameClass() == "Ball") {
		putchar(' ');
	}
}

void Graphic::drawBoard(Board a)
{
	pair<int, int> b, c;
	// Rào trên
	b = a.getTopLeft();
	c = a.getTopRight();

	//màu đỏ
	Utils::setColorText(12, 0);

	for (int x = b.first; x <= c.first; x++)
	{
		// Di chuyển đến tọa độ cần vẽ 
		Utils::gotoXY(x, b.second);
		// Vẽ rào trên
		putchar(219);
	}

	// Rào dưới
	b = a.getBotLeft();
	c = a.getBotRight();
	for (int x = b.first; x <= c.first; x++)
	{
		// Di chuyển đến tọa độ cần vẽ 
		Utils::gotoXY(x, b.second);
		// Vẽ rào dưới
		putchar(219);
	}

	// Rào trái
	b = a.getTopLeft();
	c = a.getBotLeft();
	for (int y = b.second; y <= c.second; y++)
	{
		// Di chuyển đến tọa độ cần vẽ 
		Utils::gotoXY(b.first, y);
		// Vẽ rào trái
		putchar(219);
	}

	// Rào phải
	b = a.getTopRight();
	c = a.getBotRight();
	for (int y = b.second; y <= c.second; y++)
	{
		// Di chuyển đến tọa độ cần vẽ 
		Utils::gotoXY(b.first, y);
		// Vẽ rào phải
		putchar(219);
	}

	//màu trắng
	Utils::setColorText(15, 0);

}

void Graphic::drawPlayerWin() {

	cout << ",--.  ,--.,----.  ,--. ,--.    ,--.   ,--.,--.,--.  ,--.\n";
	cout << "\\  `.'  /'  .-. ' |  | |  |    |  |   |  ||  ||  ,'.|  |\n";
	cout << " '.    / |  | | | |  | |  |    |  |.'.|  ||  ||  |' '  |\n";
	cout << "  |   |  '  '-' ' '  '-'  '    |   ,'.   ||  ||  | `   |\n";
	cout << "  `---'   `-----'  `-----'     '--'   '--'`--'`--'  `--'\n";
}
void Graphic::drawPlayerLose() {
	cout << ",--.   ,--.,-----. ,--. ,--.     ,--.    ,-----.  ,---.  ,------.\n";
	cout << "\\  `.'  /'  . - .  '|  | |  |     |  |   '  . - .  ''   . - ' |  .---'\n";
	cout << "'.    / |  | |  ||  | |  |     |  |   |  | |  |`.  `-. |  `--, \n";
	cout << "|  |  '  ' - '  ''  ' - '  ' | '--.'  '-'  '.-' || `---.\n";
	cout << "`- - '   `-----'  `-----'      `-----' `-----' `-----' `----- - '\n";
}