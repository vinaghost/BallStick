#include "Stick.h"
#include "Utils.h"


#include <Windows.h>
#include <cstdio>

int main() {
	Stick p1(0, 0, 20, 10, 3);
	Stick p2(0, 20, 20, 10, 3);

	p1.update(0 + 20 / 2, 0);
	p2.update(0 + 20 / 2, 30);

	ULONGLONG  startTime = GetTickCount64() + 50;
	ULONGLONG  curTime;
	Utils::showConsoleCursor(false);
	while (true) {
		curTime = GetTickCount64();

		if (curTime > startTime) {


			if (GetKeyState('A') & 0x8000) {
				p1.update(p1.getX() - 1, p1.getY());
			}
			if (GetKeyState('D') & 0x8000) {
				p1.update(p1.getX() + 1, p1.getY());
			}
			if (GetKeyState('J') & 0x8000) {
				p2.update(p2.getX() - 1, p2.getY());
			}
			if (GetKeyState('L') & 0x8000) {
				p2.update(p2.getX() + 1, p2.getY());
			}
			if (GetKeyState(VK_ESCAPE) & 0x8000) {
				break;
			}

			startTime = curTime + 50;
		}

	}
	Utils::showConsoleCursor(true);
	getchar();
	return 0;
}