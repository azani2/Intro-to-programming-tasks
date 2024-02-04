#include <iostream>
using namespace std;

bool isPrime(unsigned int n) {
    if (n <= 1)
        return false;

    double sqrtN = sqrt(n);

    for (int i = 2; i <= sqrtN; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int numberOfPrimeFactors(int n) {
    int primeFactorsCount = 0;
    int nCopy = n;
    for (int i = n; i > 1; i--)
    {
        if (!isPrime(i))
            continue;

        if (n % i == 0)
            primeFactorsCount++;

        while (nCopy % i == 0) {
            nCopy /= i;
        }
        if (nCopy == 1)
            return primeFactorsCount;//ne se broi edinicata(1), ako se broi 
                                        //(kato prime factor) izhodut ne e sushtiq kato po uslovie
    }
}
int numberOfNumbersWithKPrimeFactors(int intervalStart, int intervalEnd, int k) {
    int numberOfFoundNumbers = 0;
    for (int  i = intervalStart; i <= intervalEnd; i++)
    {
        int s = numberOfPrimeFactors(i);
        if (s == k)
            numberOfFoundNumbers++;
    }
    return numberOfFoundNumbers;
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    cout << numberOfNumbersWithKPrimeFactors(a, b, k);
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
