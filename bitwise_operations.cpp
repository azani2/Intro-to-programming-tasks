#include <iostream>
using namespace std;

void init(int* arr, const size_t size, int& arrLen) {
	arrLen = 0;
	for (size_t i = 0; i < size; i++)
	{
		int temp;
		cin >> temp;
		*arr = temp;
		if (*arr == -1)
			break;
		arr++;
		arrLen++;
	}
}

void printArr(const int* arr, const size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << *arr << " ";
		arr++;
	}
}

//task 1
int onlyOccurranceElement(const int* arr, const size_t size) {
	int res = *arr;
	arr++;
	for (size_t i = 1; i < size; i++)
	{
		res ^= *arr;
		arr++;
	}
	return res;
}

//task 2

int numberOfOnesInBinary(int n) {
	int mask = 1;
	int count = 0;
	while (n != 0)
	{
		if (n & mask) {
			count++;
		}
		n >>= 1;
	}
	return count;
}

//task 3

int flipRightmostOne(int n) {
	int pushes = 0;
	while (!(n & 1)) {
		n >>= 1;
		pushes++;
	}
	n--;
	n <<= pushes;
	return n;
}

int main()
{
	//1
	int arr[10];
	int arrLen = 0;
	int& arrl = arrLen;
	init(arr, 10, arrl);
	//printArr(arr, arrLen);
	cout << onlyOccurranceElement(arr, arrLen) << endl;//ne se kara neshto che ne e const no 
											   //raboti ok...
											   // 
	//2
	int n;
	cin >> n;
	cout << numberOfOnesInBinary(n) << endl;

	//3
	cout << flipRightmostOne(n) << endl;

}