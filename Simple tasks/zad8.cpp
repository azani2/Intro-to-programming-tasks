#include <iostream>
using namespace std;

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

bool hasSameDigitsOnly(int n) {
	int digitsNumber = digitsCount(n);
	int lastDigit = n % 10;
	n /= 10;
	for (int i = 0; i < digitsNumber - 1; i++)
	{
		int currentDigit = n % 10;
		n /= 10;
		if (lastDigit != currentDigit)
			return false;

		lastDigit = currentDigit;
	}
	return true;
}

int main()
{
    int n;
    cin >> n;
	cout << (hasSameDigitsOnly(n) ? "true" : "false");
}

