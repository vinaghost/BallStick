
#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"

#include <windows.h>
#include <cstdio>

void Utils::fixConsoleWindow() {

	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	/*https://stackoverflow.com/questions/21238806/how-to-set-output-console-width-in-visual-studio*/
	RECT r;
	GetWindowRect(consoleWindow, &r);

	MoveWindow(consoleWindow, r.left, r.top, 900, 700, TRUE);

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	/*https://cboard.cprogramming.com/cplusplus-programming/97959-[ask]-how-remove-scrollbar.html*/
	CONSOLE_SCREEN_BUFFER_INFO info;

	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size = {
		(short int)(info.srWindow.Right - info.srWindow.Left + 1),
		(short int)(info.srWindow.Bottom - info.srWindow.Top + 1),
	};
	SetConsoleScreenBufferSize(handle, new_size);

	/*https://stackoverflow.com/questions/33975912/how-to-set-console-font-to-raster-font-programmatically*/
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 16;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(handle, FALSE, &cfi);

}
void Utils::showConsoleCursor(bool show) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = show;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void Utils::gotoXY(int pX, int pY) {
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

COORD Utils::getCursor() {
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi)) {
		return cbsi.dwCursorPosition;
	}
	else {
		COORD invalid = { 0, 0 };
		return invalid;
	}
}

void Utils::clearScreen() {
	/*
	for (int i = 0; i < 80; i++) {
		printf("\n");
	}
	gotoXY(0, 0);
	*/

	system("cls");
}