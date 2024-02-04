using namespace std;
#include <iostream>

int height(char c) {
	if (c == 'S')
	{
		return 1;
	}
	if (c - '0' == 69)
	{
		return 26;
	}
	if (c < 'a' || c>'z')
	{
		return 100;
	}
	return (c - 97) + 1;
}

void findStart(char matrix[5][9], int& startX, int& startY) {
	startX = 0;
	startY = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (matrix[i][j] == 'S') {
				startX = i;
				startY = j;
			}
		}
	}
}

void findEnd(char matrix[5][9], int& endX, int& endY) {
	endX = 3;
	endY = 6;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (matrix[i][j] == 'E') {
				endX = i;
				endY = j;
			}
		}
	}
}

bool hasUnvisited(bool visited[][8], int sizeN, int sizeM) {
	for (int i = 0; i < sizeN; i++)
	{
		for (int j = 0; j < sizeM; j++)
		{
			if (!visited[i][j])
			{
				return true;
			}
		}
	}
	return false;
}

void nextClosest(char matrix[5][9], int currentX, int currentY, bool visited[5][8], int& nextX, int& nextY) {
	nextX = nextY = 0;
	unsigned int currentHeight = height(matrix[currentX][currentY]);

	if (currentY > 0 //go left
		&& !visited[currentX][currentY-1]
		&& height(matrix[currentX][currentY - 1]) <= (currentHeight + 1))
	{
		nextX = currentX;
		nextY = currentY - 1;
	}
	else if (currentX > 0 //go up
		&& !visited[currentX - 1][currentY]
		&& height(matrix[currentX - 1][currentY]) <= (currentHeight + 1))
	{
		nextX = currentX - 1;
		nextY = currentY;
	}
	else if (currentY < 7 //go right
		&& !visited[currentX][currentY + 1]
		&& height(matrix[currentX][currentY + 1]) <= (currentHeight + 1))
	{
		nextX = currentX;
		nextY = currentY + 1;
	}
	else if (currentX < 4 //go down
		&& !visited[currentX + 1][currentY]
		&& height(matrix[currentX + 1][currentY]) <= (currentHeight + 1))
	{
		nextX = currentX + 1;
		nextY = currentY;
	}
	else //nowhere to go
	{
		nextX = currentX;
		nextY = currentY;
	}
}

void adjacencyMatrix(int visited[5][8], int x, int y, bool adjM[2][2]) {
	if (x > 0)
		adjM[0][0] = visited[x - 1][y];
	else
		adjM[0][0] = 1;
	if (x < 4)
		adjM[0][1] = visited[x + 1][y];
	if (y > 0)
		adjM[1][0] = visited[x][y - 1];
	if (y < 8)
		adjM[1][1] = visited[x][y + 1];
}

void walk(char matrix[5][9], int dist[5][8], int currentX, int currentY, bool visited[5][8], int endX,int endY) {
	int nextX = 0, nextY = 0;
	cout << "[" << currentX << ", " << currentY << "]" << endl;

	
	if (currentX == endX && currentY == endY)
		return;
	while (hasUnvisited(visited, 5, 8)) {
		nextClosest(matrix, currentX, currentY, visited, nextX, nextY);
		if (nextX == currentX && nextY == currentY) {
			return;
		}
		int altDist = dist[currentX][currentY] + 1;
		if (altDist < dist[nextX][nextY])
		{
			dist[nextX][nextY] = altDist;
		}
		walk(matrix, dist, nextX, nextY, visited, endX, endY);
		visited[currentX][currentY] = true;
	}
}

void pathCheck(char matrix[5][9], int startX, int startY, int endX, int endY)  {
	bool visited[5][8] = { 0 };
	int dist[5][8] = { 100 };
	dist[startX][startY] = 0;
	int currentX = startX, currentY = startY;

	dist[startX][startY] = 0;
	int nextX = 0, nextY = 0;
	walk(matrix, dist, nextX, nextY, visited, endX, endY);

}

int main()
{
	char testMatrix[5][9] = { "Sabqponm", "abcryxxl", "accszExk", "acctuvwj", "abdefghi" };
	char path[50];
	int startX, startY, endX, endY;
	findStart(testMatrix, startX, startY);
	findEnd(testMatrix, endX, endY);
	pathCheck(testMatrix, startX, startY, endX, endY);
}