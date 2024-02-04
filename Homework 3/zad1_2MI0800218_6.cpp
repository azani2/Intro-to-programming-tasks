#include <iostream>
using namespace std;

const int SIZE = 4;

//transponirane
void initArray(int* arr, const size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		int temp;
		cin >> temp;
		*arr = temp;
		arr++;
	}
}

void initMatrix(int arr[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
	{
		initArray(arr[i], SIZE);
	}
}

void printMatrix(const int arr[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << " " << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void transpose(const int arr[SIZE][SIZE], int trArr[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			trArr[i][j] = arr[j][i];
		}
	}
}

int main()
{
    int matrix[SIZE][SIZE];
	cout << "Size: " << SIZE << " x " << SIZE << endl;
	initMatrix(matrix);
    printMatrix(matrix);
	cout << endl;

	int transposeMatrix[SIZE][SIZE];
	transpose(matrix, transposeMatrix);
	printMatrix(transposeMatrix);
}
