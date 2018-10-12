#include "Display.h"
#include <iostream>
#include "Array1DThatIsActually2D.h"
#include <Windows.h>
#include <string>

void display1DArrayThatIsActually2D(const short state[], const int maxX, const int maxY)
{
	char *displ;
	int s = maxX * maxY + maxY;
	displ = new char[s];

	int i = 0;
	for (int y = 0; y < maxY; y++)
	{
		for (int x = 0; x < maxX; x++)
		{
			char ch;
			switch (getElementIn1DArray(state, x, y, maxX))
			{
				case 0:
					ch = '0';
					break;
				case 1:
					ch = '1';
					break;
				case 2:
					ch = '2';
					break;
				case 3:
					ch = '3';
					break;
				case 4:
					ch = '4';
					break;
				case 5:
					ch = '5';
					break;
				case 6:
					ch = '6';
					break;
				case 7:
					ch = '7';
					break;
				case 8:
					ch = '8';
					break;
				case 9:
					ch = '9';
					break;
				case -1:
					ch = 178;
					break;
				default:
					ch = 'E';
					break;
			}
			displ[i++] = ch;
		}
		displ[i++] = '\n';
	}
	// idk why char* prints incorrectly (it somehow gets undefined behaviour so random string is printed at the end plus sometimes it makes beeping sounds)
	auto str = std::string(displ, s);

	std::cout << str << "\n";

	delete[] displ;
}

void clearConsole(char fill)
{
	COORD tl = {0,0};
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(handle, fill, cells, tl, &written);
	FillConsoleOutputAttribute(handle, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(handle, tl);
}
