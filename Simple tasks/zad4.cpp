#include <iostream>
using namespace std;

int absoluteValue(int n) {
	if (n <= 0) {
		return -n;
	}
	return n;
}

unsigned int digitsCount(long n) {
	if (n == 0)
		return 0;

	int res = 0;

	while (n != 0) {
		n /= 10;
		res++;
	}

	return res;
}

long long concat(long n1, long n2) {
	n2 = absoluteValue(n2);

	int n2DigitsNumber = digitsCount(n2);
	for (int i = 0; i < n2DigitsNumber; i++)
	{
		n1 *= 10;
	}
	return n1 + n2;
}

int main()
{
    long n1, n2;
    cin >> n1 >> n2;
    cout << concat(n1, n2);
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
