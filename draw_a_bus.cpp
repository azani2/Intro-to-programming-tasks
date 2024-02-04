#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void drawSpaces(int p) {
	for (int i = 0; i < p; i++)
	{
		cout << ' ';
	}
}

void drawBus(int r) {
	for (int i = 1; i < 6; i++)
	{
		drawSpaces(r);
		for (int j = 1; j <= 30; j++)
		{
			if (i == 1)
			{
				if (j < 2)
				{
					cout << ' ';
				}
				else if (j <= 27)
				{
					cout << '_';
				}
			}
			if (i == 2)
			{
				switch (j)
				{
				case 1:
				case 5:
				case 11:
				case 17:
				case 22:
				case 24:
					cout << '|';
					break;
				case 28:
					cout << '\\';
					break;
				default:
					cout << ' ';
					break;
				}
			}
			if (i == 3)
			{
				switch (j)
				{
				case 1:
				case 5:
				case 11:
				case 17:
				case 22:
				case 24:
					cout << '|';
					break;
				case 29:
					cout << '\\';
					break;
				case 30:
					cout << ' ';
					break;
				default:
					cout << '_';
					break;
				}
			}
			if (i == 4)
			{
				switch (j)
				{
				case 1:
				case 22:
				case 24:
					cout << '|';
					break;
				case 30:
					cout << '\\';
					break;
				default:
					cout << ' ';
					break;
				}
			}
			if (i == 5)
			{
				switch (j)
				{
				case 1:
					cout << '`';
					break;
				case 4:
				case 7:
				case 24:
					cout << '(';
					break;
				case 5:
				case 8:
				case 25:
					cout << 'o';
					break;
				case 6:
				case 9:
				case 26:
					cout << ')';
					break;
				case 30:
					cout << "'";
					break;
				default:
					cout << '-';
					break;
				}
			}
		}
		cout << endl;
	}
}

int main()
{
	for (int i = 0; i < 30; i++)
	{
		drawBus(i);
		Sleep(200);
		system("CLS");
	}
	drawBus(31);
}
