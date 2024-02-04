#include <iostream>
using namespace std;

int absoluteValue(int a) {
	return a * (a < 0 ? (-1) : 1);
}

bool containsDigit(int n, unsigned int d) {
	if (d > 9)
		return false;

	while (n != 0) {
		if (n % 10 == d) {
			return true;
		}
		n /= 10;
	}
	return false;
}

bool isSubset(int a, int b) {
	a = absoluteValue(a);
	b = absoluteValue(b);

	while (a != 0) {
		if (!contains(b, a % 10)) {
			return false;
		}
		a /= 10;
	}
	return true;
}

int smallerThan(int a, int b) {
	bool aSubsB = isSubset(a, b);
	bool bSubsA = isSubset(b, a);
	if (aSubsB) {
		if (bSubsA) {
			return 3;// equals
		}
		return 1;//a is smaller
	}
	if (bSubsA) {
		return 2;//b is smaller
	}
	return 0;//uncomparable
}

int main()
{
	int n1, n2;
	cin >> n1 >> n2;
	switch (smallerThan(n1, n2)) {
	case 0:
		cout << "Not comparable";
		break;
	case 1:
		cout << "First is weaker";
		break;
	case 2:
		cout << "Second is weaker";
		break;
	case 3:
		cout << "Equal strength";
		break;
	default:
		break;
	}
	return 0;
}