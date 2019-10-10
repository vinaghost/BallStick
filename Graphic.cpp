#include <cstdio>

#include "Graphic.h"
#include "Utils.h"

void Graphic::drawBall(Ball b) {
	Utils::gotoXY(b.getX(), b.getY());
	putchar('O');
}
void Graphic::deleteBall(Ball b) {
	Utils::gotoXY(b.getX(), b.getY());
	putchar(' ');
}