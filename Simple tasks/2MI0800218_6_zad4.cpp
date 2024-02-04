#include <iostream>
using namespace std;

unsigned int digitsCount(int n) {
	unsigned int count = 0;
	while (n != 0) {
		n /= 10;
		count++;
	}
	return count;
}

unsigned int twoToPositivePower(unsigned int d) {
	return (1 << d);
}

unsigned int toBinaryFormatted(int n) {//това е от семинарите
	int res = 0;
	int toAdd = 1;
	while (n != 0) {
		if (n % 2 == 1) {
			res += toAdd;
		}
		toAdd *= 10;
		n /= 2;
	}
	return res;
}

unsigned int subnumber(int n, unsigned int binarySubset) {
	int res = 0;
	int mult = 1;
	while (binarySubset != 0)
	{
		int binaryDigit = binarySubset % 10;
		res += binaryDigit*(n % 10)*mult;

		if (binaryDigit)
			mult *= 10;
		binarySubset /= 10;
		n /= 10;
	}
	return res;
}

bool digitReoccurrs(int n, unsigned int d) {
	if (d > 9 || n == 0 || d == 0)
		return 0;

	int count = 0;
	while (n != 0) {
		if (n % 10 == d) {
			count++;

			if (count == 2)
				return true;
		}
		n /= 10;
	}
	return false;
}

bool hasPairwiseDistinctDigits(int n) {
	while (n != 0) {
		unsigned int d = n % 10;
		if (digitReoccurrs(n, d))
			return false;
		n /= 10;
	}
	return true;
}

unsigned int sumOfSubnumbers(int n) {
	int d = digitsCount(n);
	int subsCount = twoToPositivePower(d) - 1;
	int sum = 0;
	for (int i = 1; i <= subsCount; i++)
	{
		int binarySubset = toBinaryFormatted(i);//int could overflow
		int subnum = subnumber(n, binarySubset);
		if (hasPairwiseDistinctDigits(subnum))
			sum += subnum;
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;
	cout << sumOfSubnumbers(n);
}
