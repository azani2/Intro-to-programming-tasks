using namespace std;
#include <iostream>

const size_t MAX_SIZE = 10;

bool isPrime(int n) {
	if (!n) {
		return false;
	}
	double sqr = sqrt(n);
	for (int i = 2; i < sqr; i += 2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int** createMatrix(int n, int m) {
	int** matrix = new int* [n];
	for (int  i = 0; i < n; i++)
	{
		matrix[i] = new int [m] { 0 };
	}
	return matrix;
}

char** createCharMatrix(int n, int m) {
	char** matrix = new char* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new char [m];
	}
	return matrix;
}

void printMatrix(int n, int m, int** matrix) {
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void freeMatrix(int n, int** matrix) {
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void freeMatrix(int n, char** matrix) {
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

bool predAboveMainDiagonal(int** matrix, int n, bool(*pred)(int)) {
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (pred(matrix[i][j]))
			{
				return true;
			}
		}
	}
	return false;
}

char* readWordsBackwards(const char matrix[][MAX_SIZE], int wordsCount) {
	int maxSize = wordsCount * MAX_SIZE;
	char* sentence = new char [maxSize] { 0 };
	int index = 0;
	for (int i = wordsCount - 1; i >= 0; i--)
	{
		int wordLength = strlen(matrix[i]);
		for (int j = wordLength - 1; j >= 0; j--)
		{
			if (matrix[i][j] != '\0')
			{
				sentence[index] = matrix[i][j];
				index++;
			}
		}

		if (i)
		{
			sentence[index] = ' ';
			index++;
		}
		else
		{
			sentence[index] = '\0';
		}
	}
	return sentence;
}

void print(const int* arr, size_t n) {
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool contains(const int* arr, size_t n, int c) {
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == c)
		{
			return true;
		}
	}
	return false;
}

void findPaths(int startOg, int start, int end, int midpoint, const int edges[22][2], bool visited[8], int path[11], int index = 0) {
	if (start == end) {
		path[index] = start;
		if (contains(path, index + 1, midpoint))
			print(path, index + 1);
		return;
	}
	visited[start] = 1;
	path[index] = start;

	for (int i = 0; i < 22; i++)
	{
		if (edges[i][0] > start)
			break;
		if (edges[i][0] != start)
			continue;

		if (edges[i][0] == start)
		{
			if (!visited[edges[i][1]])
				findPaths(startOg, edges[i][1], end, midpoint, edges, visited, path, index + 1);
		}
	}
	visited[start] = 0;
}

int main()
{
	int** matrix = createMatrix(5, 5);
	matrix[1][3] = 3;
	printMatrix(5, 5, matrix);
	cout << predAboveMainDiagonal(matrix, 5, isPrime) << endl;

	char wordsMatrix[3][MAX_SIZE] = { "llams", "era", "stac" };
	cout << "Ordinary: " << wordsMatrix[0] << " " << wordsMatrix[1] << " " << wordsMatrix[2] << endl;
	char* backwardsSentence = readWordsBackwards(wordsMatrix, 3);
	cout << "Backwards: " << backwardsSentence << endl;

	cout << "Start: 1, End: 7, Midpoint: 4, Edges: " << endl <<
		"{ 1, 2 }, { 1, 3 }, { 1, 4 }" << endl <<
		"{ 2, 1 }, { 2, 4 }, { 2, 6 }" << endl <<
		"{ 3, 1 }, { 3, 7 }" << endl <<
		"{ 4, 1 }, { 4, 2 }, { 4, 5 }, { 4, 7 }" << endl <<
		"{ 5, 4 }, { 5, 6 }, { 5, 7 }" << endl <<
		"{ 6, 2 }, { 6, 5 }, { 6, 7 }" << endl <<
		"{ 7, 3 }, { 7, 4 }, { 7, 5 }, { 7, 6 }" << endl <<
		"Paths:" << endl;
	bool visited[8] = { 0 };
	int edges[22][2]{
		{1, 2}, {1, 3}, {1, 4},
		{2, 1}, {2, 4}, {2, 6},
		{3, 1}, {3, 7},
		{4, 1}, {4, 2}, {4, 5}, {4, 7},
		{5, 4}, {5, 6}, {5, 7},
		{6, 2}, {6, 5}, {6, 7},
		{7, 3}, {7, 4}, {7, 5}, {7, 6}
	};
	int path[11] = { 0 };
	findPaths(1, 1, 7, 4, edges, visited, path);

	delete[] backwardsSentence;
	freeMatrix(5, matrix);
}
