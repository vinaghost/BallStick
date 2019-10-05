#pragma once
#include <windows.h>

class Utils {
public:
	static void fixConsoleWindow();
	static void gotoXY(int, int);
	static COORD getCursor();
	static void clearScreen();
};

