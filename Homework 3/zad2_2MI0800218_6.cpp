#include <iostream>
using namespace std;

const int SIZE = 5;

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

bool reflexivityCheck(int matrix[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
	{
		if (!matrix[i][i])
			return false;
	}
	return true;
}

bool symmetryCheck(int matrix[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i; j < SIZE; j++)
		{
			if (matrix[i][j] != matrix[j][i])
				return false;
		}
	}
	return true;
}

bool isEquivaletRelation(int matrix[SIZE][SIZE]) {
	if (!reflexivityCheck(matrix) || !symmetryCheck(matrix))
		return false;
	//tranzitivna?
}

int main()
{
    int matrix[SIZE][SIZE];
	cout << "Size: " << SIZE << " x " << SIZE << endl;
	initMatrix(matrix);
	printMatrix(matrix);
	cout << endl;
}