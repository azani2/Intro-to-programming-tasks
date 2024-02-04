#include <iostream>
using namespace std;

int absoluteValue(int n) {
	if (n <= 0) {
		return -n;
	}
	return n;
}

unsigned int digitsCount(long long n) {
	if (n == 0)
		return 0;

	int res = 0;

	while (n != 0) {
		n /= 10;
		res++;
	}

	return res;
}


int reversedNumber(int n) {
	n = absoluteValue(n);
	int reversed = 0;
	int digitsNumber = digitsCount(n);

	for (int i = 0; i < digitsNumber; i++)
	{
		int r = n % 10;
		n /= 10;
		reversed += r;
		if (n > 0)
			reversed *= 10;
	}
	return reversed;
}

bool sortedDigitsAsc(int n) {
	int digitsNumber = digitsCount(n);
	int lastDigit = n % 10;
	n /= 10;
	for (int i = 0; i < digitsNumber - 1; i++)
	{
		int currentDigit = n % 10;
		n /= 10;
		if (lastDigit < currentDigit)
			return false;

		lastDigit = currentDigit;
	}
	return true;
}

bool sortedDigitsDesc(int n) {
	int digitsNumber = digitsCount(n);
	int lastDigit = n % 10;
	n /= 10;
	for (int i = 0; i < digitsNumber - 1; i++)
	{
		int currentDigit = n % 10;
		n /= 10;
		if (lastDigit > currentDigit)
			return false;

		lastDigit = currentDigit;
	}
	return true;
}

int concat(int n1, int n2) {
	if (n2 == 0)
		return n1;

	n2 = absoluteValue(n2);

	int n2DigitsNumber = digitsCount(n2);
	for (int i = 0; i < n2DigitsNumber; i++)
	{
		n1 *= 10;
	}
	return n1 + n2;

}

int concatDigitNTImes(unsigned d, int n) {
	int res = d;
	if (n == 0)
		return 0;
	for (int i = 1; i < n; i++)
	{
		res = concat(d, d);
	}
	return res;
}

int digitInNumberCount(int n, int d) {
	int digitsNumber = digitsCount(n);
	int counter = 0;
	for (int i = 0; i < digitsNumber; i++)
	{
		if (n % 10 == d)
			counter++;
		n /= 10;
	}
	return counter;
}

int sortDigits(int n) {
	//if (sortedDigitsAsc(n))
	//	return n;
	//if (sortedDigitsDesc)
	//	return reversedNumber(n);

	
	int res = 0;
	for (int i = 1; i < 10; i++)
	{
		res = concat(res, concatDigitNTImes(i, digitInNumberCount(n, i)));
	}
	return res;
}

int main()
{
    int n;
    cin >> n;
	cout << sortDigits(n);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
