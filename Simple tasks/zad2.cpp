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

int main()
{

	long long n;
	cin >> n;
	cout << digitsCount(n);
}




