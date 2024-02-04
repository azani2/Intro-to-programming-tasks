#include <iostream>
#include <windows.h>
using namespace std;

const size_t MAX_SIZE = 10;
bool win = false;
bool lose = false;

bool validGrid(int gridSize, int m) {
	bool valid = true;
	if (gridSize < 3 || gridSize > 10) {
		cout << "Invalid grid size." << endl;
		valid = false;
	}
	if (m < 1 || m > 3 * gridSize) {
		cout << "Mines must be between 1 and 3xn." << endl;
		valid = false;
	}
	return valid;
}

bool validCoordinates(int a, int b, int gridSize) {
	return (a >= 0 && a < gridSize && b >= 0 && b < gridSize);
}

void generateMines(int grid[MAX_SIZE][MAX_SIZE], int m, int gridSize) {
	int maxGridIndex = gridSize - 1;
	for (int i = 1; i <= m; i++) {
		int a = rand() % maxGridIndex + 1;//vij rand-a kak raboti
		int b = rand() % maxGridIndex + 1;//randoma neshto ne e mnogo random
		while (!validCoordinates(a, b, gridSize) || grid[a][b] == -1) {
			a = rand() % maxGridIndex + 1;
			b = rand() % maxGridIndex + 1;
		}
		grid[a][b] = -1;
	}
}

void incrementMineNeighbours(int grid[MAX_SIZE][MAX_SIZE], int gridSize, int x, int y) {
	int maxX = x + 1;
	int maxY = y + 1;

	for (int dX = x - 1; dX <= maxX; dX++) {
		for (int dY = y - 1; dY <= maxY; dY++) {
			if (validCoordinates(dX, dY, gridSize) && grid[dX][dY] != -1) {
				grid[dX][dY]++;
			}
		}
	}
}

void fillOriginalGrid(int grid[MAX_SIZE][MAX_SIZE], int gridSize) {
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if (grid[i][j] != -1) {
				grid[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if (grid[i][j] == -1) {
				incrementMineNeighbours(grid, gridSize, i, j);
			}
		}
	}
}

void printGrid(int grid[MAX_SIZE][MAX_SIZE], int gridSize) {
	cout << "   | ";
	for (int i = 1; i <= gridSize; i++) {
		cout << " " << i << " ";
	}
	cout << endl << endl;
	// dotuk kozmetika

	for (int i = 0; i < gridSize; i++) {
		cout << " " << (i + 1) << " | "; //kozmetika

		for (int j = 0; j < gridSize; j++) {
			if (grid[i][j] == -1) {
				cout << " * ";
			}
			else if (grid[i][j] == -3) {
				cout << " ? ";
			}
			else {
				cout << " " << grid[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void fillDisplayGrid(int displayGrid[MAX_SIZE][MAX_SIZE]) {
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		for (size_t j = 0; j < MAX_SIZE; j++)
		{
			displayGrid[i][j] = -3;
		}
	}
}

void displayZerosNeighbours(int ogGrid[MAX_SIZE][MAX_SIZE], int gridSize, int displayGrid[MAX_SIZE][MAX_SIZE], int x, int y) {
	int maxX = x + 1;
	int maxY = y + 1;

	for (int dX = x - 1; dX <= maxX; dX++) {
		for (int dY = y - 1; dY <= maxY; dY++) {
			if (validCoordinates(dX, dY, gridSize)) {
				if (displayGrid[dX][dY] == -3)//za da ne cikli bezkraino zradi susedni nuli
				{
					displayGrid[dX][dY] = ogGrid[dX][dY];
					if (ogGrid[dX][dY] == 0) {
						displayZerosNeighbours(ogGrid, gridSize, displayGrid, dX, dY);
					}
				}
			}
		}
	}
}

void open(int ogGrid[MAX_SIZE][MAX_SIZE],int gridSize, int displayGrid[MAX_SIZE][MAX_SIZE], int x, int y)
{
//bomb -> game over
//no bomb -> display number 
		//1) 0 -> display surrounding numbers -> ako nqkoe ot tqh e 0
												//se izvikva rekursivno
												//i za negovite susedi
		//2) ne 0 -> nishto, prosto go izpisva
	if (ogGrid[x][y] == -1) {
		printGrid(ogGrid, gridSize);
		cout << endl << "GAME OVER" << endl;
		return;
		lose = true;
	}
	else if (ogGrid[x][y] == 0) {
		displayGrid[x][y] = 0;
		displayZerosNeighbours(ogGrid, gridSize, displayGrid, x, y);
	}
	else {
		displayGrid[x][y] = ogGrid[x][y];
	}

	printGrid(displayGrid, gridSize);
}

void checkWinner(int gridSize, int ogGrid[MAX_SIZE][MAX_SIZE], int displayGrid[MAX_SIZE][MAX_SIZE]) {
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			if (ogGrid[i][j] != displayGrid[i][j]) {
				return;
			}
		}
	}
	win = true;
}

void mark(int displayGrid[MAX_SIZE][MAX_SIZE], int x, int y, int gridSize) {
	// ot validaciqta vuv while v play -> displayGrid[x][y] e -3
	displayGrid[x][y] = -1;
	printGrid(displayGrid, gridSize);
}

void unmark(int displayGrid[MAX_SIZE][MAX_SIZE], int x, int y, int gridSize) {
	// ot validaciqta vuv while v play -> displayGrid[x][y] e -1
	displayGrid[x][y] = -3;
	printGrid(displayGrid, gridSize);
}

bool equalStrings(const char* first, const char* second)
{
	if (first == nullptr || second == nullptr)
		return 0; //error

	while (*first != '\0' && *second != '\0')
	{
		if (*first != *second)
			return 0;
		first++;
		second++;
	}

	if (*first == '\0' && *second == '\0')
		return 1;

	return *first == '\0' ? -1 : 1;
}// ideqta e ot githuba

void play(int ogGrid[MAX_SIZE][MAX_SIZE], int gridSize, int displayGrid[MAX_SIZE][MAX_SIZE]) {
	char command[20];
	int x, y = 0;
	cin >> command;
	char *comm = command;
	const char* openStr = "open";
	const char* markStr = "mark";
	const char* unmarkStr = "unmark";
	cin >> x;
	cin >> y;
	x--;
	y--; // vuvezhdat se ot 1 do n zashtoto taka podskazva kozmetikata

	while (!validCoordinates(x, y, gridSize) 
		|| (!equalStrings(command, openStr) && !equalStrings(command, markStr) && !equalStrings(command, unmarkStr))
		|| (equalStrings(command, unmarkStr) && displayGrid[x][y] != -1) //za da otmarkirame kutiika trqbva da sme q markirali
		|| (!equalStrings(command, unmarkStr) && displayGrid[x][y] != -3)) //otvorena kutiika ne moxe da se markira ili otvori pak
	{
		cout << "Invalid input! Coordinates must range between 1 and " << gridSize 
			<< " and refer to an unopened box to open. Command must be <open>, <mark> or <unmark>." << endl;
		cout << "Enter command, x coordinates and y coordinates. (<open / mark / unmark> <x> <y>)" << endl;
		cin >> command;
		cin >> x;
		cin >> y;
		x--;
		y--;
	}

	system("CLS");

	if (equalStrings(command, openStr)) {
			open(ogGrid, gridSize, displayGrid, x, y);
	}
	else if (equalStrings(command, markStr)) {
		mark(displayGrid, x, y, gridSize);
	} 
	else { //unmark
		unmark(displayGrid, x, y, gridSize);
	}

	checkWinner(gridSize, ogGrid, displayGrid);
	if (win)
	{
		cout << "Congratulations! You win!";
		return;
		system("pause");
	}

	system("pause");
}

int main()
{
	int n, minesCount;
	cout << "Enter grid size and mines count." << endl;
	cin >> n >> minesCount;
	while (!validGrid(n, minesCount)) {
		cin >> n >> minesCount;
	}

	int grid[MAX_SIZE][MAX_SIZE];
	generateMines(grid, minesCount, n);//dotuk ok
	fillOriginalGrid(grid, n);
	cout << "Answer (za da testvam po-lesno):" << endl;
	printGrid(grid, n);
	system("pause");


	int playGrid[MAX_SIZE][MAX_SIZE];
	fillDisplayGrid(playGrid);
	// play() -> open/mark/unmark (cin) -> 
			// koordinatite (validCoordinates() s cikul za prezapisvane (cin)) ->
			// switch command
	int turnsCounter = 1;
	while (win == false && lose == false)
	{
		cout << "Turn: " << turnsCounter << endl;
		turnsCounter++;
		cout << "Enter command, x coordinates and y coordinates. (<open / mark / unmark> <x> <y>)" << endl;
		play(grid, n, playGrid);
	}
	cout << endl << "Total turns: " << turnsCounter << endl;
}