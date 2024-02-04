#include <iostream>
using namespace std;

const int N = 5;
const int M = 4;
const int K = 3;

void initArray(int* arr, const size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		int temp;
		cin >> temp;
		*arr = temp;
		arr++;
	}
}

void initMatrices(int arr1[N][M], int arr2[M][K]) {
	cout << "Size: " << N << " x " << M << endl;
	for (int i = 0; i < N; i++)
	{
		initArray(arr1[i], M);
	}

	cout << "Size: " << M << " x " << K << endl;
	for (int i = 0; i < M; i++)
	{
		initArray(arr2[i], K);
	}
}

void printMatrices(const int arr1[N][M], const int arr2[M][K]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << " " << arr1[i][j] << " ";
		}
		cout << " | ";
		if (i < M)
		{
			for (int j = 0; j < K; j++)
			{
				cout << " " << arr2[i][j] << " ";
			}
		}
		cout << endl;
	}
	if (N < M) {
		for (int i = N; i < M; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cout << "   ";
			}
			cout << " | ";
			for (int j = 0; j < K; j++)
			{
				cout << " " << arr2[i][j] << " ";
			}
			cout << endl;
		}
	}
}

int calcElement(int arr1rowI[M], int arr2[M][K], int j) {
	int c = 0;
	for (int s = 0; s < M; s++)
	{
		c += arr1rowI[s] * arr2[s][j];
	}
	return c;
}

void multiplyMatrices(int arr1[N][M], int arr2[M][K], int resultArr[N][K]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			resultArr[i][j] = calcElement(arr1[i], arr2, j);
		}
	}
}

void printMatrix(const int arr[N][K]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cout << " " << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int m1[N][M];
	int m2[M][K];
	initMatrices(m1, m2);
	cout << "Multiplying" << endl;
	printMatrices(m1, m2);
	cout << endl;
	int mResult[N][K];
	multiplyMatrices(m1, m2, mResult);

	cout << "Result" << endl;
	printMatrix(mResult);
}
