#include "Array1DThatIsActually2D.h"

bool isBorder(int x, int y, int maxX, int maxY)
{
	if (x == 0 || x == maxX - 1
		||
		y == 0 || y == maxY - 1)
		return true;
	return false;
}

void indexToXY(int i, int &x, int &y, int maxX)
{
	x = i % maxX;
	y = i / maxX;
}
