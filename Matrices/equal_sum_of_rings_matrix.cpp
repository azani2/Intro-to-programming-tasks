using namespace std;
#include <iostream>

const size_t MAX_SIZE = 102;

bool equalRings(int matrix[][MAX_SIZE], int n, int &i, int &j) {
	int ogSum = 0, sum = 0;
	int start = (n / 2) - 1;
	int rings = n / 2;
	if (n % 2)
		ogSum = matrix[start][start];
	else
		ogSum = matrix[start][start] + matrix[start + 1][start] + matrix[start][start + 1] + matrix[start + 1][start + 1];
	
	for (int i = 1; i < rings; i++) {
		int st = start - i;
		int ed = start + i + 1;
		sum = 0;
		for (int j = st; j <= ed; j++) //upper and lower row
		{
			sum += matrix[st][j] + matrix[ed][j];
		}

		for (int j = st; j < ed; j++)
		{
			sum += matrix[j][st] + matrix[j][ed];
		}
		cout << sum << endl;
		if (sum != ogSum)
		{
			i = ed;
			j = ed;
			return false;
		}
	}
	return true;
}

void printMatrix(int matrix[][MAX_SIZE], int n, int m) {
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (matrix[i][j] >= 0 && matrix[i][j] < 10)
				cout << " " << matrix[i][j] << " ";
			else
				cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int matrix[6][MAX_SIZE] {
		{1, 0, 2, -3, 5, -2},
		{-5, 8, 2, 5, -2, 1},
		{1, 10, 5, 8, 0, 0},
		{0, 3, 2, 5, 4, -3},
		{2, 0, -7, 5, 6, 3},
		{10, 2, 0, 2, 3, 1}
	};
	printMatrix(matrix, 6, 6);
	int i = 0, j = 0;
	cout << equalRings(matrix, 6, i, j) << ", i, j: " << i << ", " << j << endl;
	cin >> i;

}