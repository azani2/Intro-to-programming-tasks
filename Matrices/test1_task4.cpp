#include <iostream>
using namespace std;

void init(char** matrix, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		cout << "Row " << 1 + i << ": ";
		for (int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
		matrix[i][m] = '\0';
	}
}

void freeMatrix(int n, char** matrix) {
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void printMatrix(char** matrix, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

bool rowWithCRecurringChExists(char** matrix, int n, int m, char ch, int c) {
	int count = 0;
	bool lastWasC = false;
	for (int i = 0; i < n; i++)
	{
		count = 0;
		lastWasC = false;
		for (int j = 0; j < m; j++)
		{
			int current = matrix[i][j] - 0;
			int cmp = ch - 0;
			if (current != cmp)
			{
				count = 0;
				lastWasC = false;
			}
			else if (current == cmp && lastWasC)
			{
				count++;
				lastWasC = true;
			}
			else if (current == cmp && !lastWasC)
			{
				count = 1;
				lastWasC = true;
			}

			if (count == c)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
    const size_t MAX_SIZE = 512;
    char** matrix = new char*[MAX_SIZE];

	for (int i = 0; i < MAX_SIZE; i++)
	{
		matrix[i] = new char[MAX_SIZE];
	}

	int n = 513, m = 513;
	while (n > MAX_SIZE || m > MAX_SIZE) {
		cout << "Size: ";
		cin >> n >> m;
	}

	init(matrix, n, m);
	cout << "Matrix: " << endl;
	printMatrix(matrix, n, m);

	char ch;
	cout << "Ch: ";
	cin >> ch;
	int count = 0;
	cout << "Count: ";
	cin >> count;

	cout << rowWithCRecurringChExists(matrix, n, m, ch, count);
	freeMatrix(n, matrix);
}