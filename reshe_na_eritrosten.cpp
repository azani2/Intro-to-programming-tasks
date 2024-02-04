#include <iostream>
using namespace std;

void allPrimes(int n, bool* primes)
{
    primes[0] = primes[1] = primes[n] = false;
    int i = 2;
    while (i*i <= n)
    {
        if (primes[i]) //if i is not yet marked as not prime => is prime
        {
            for (int j = i*i ; j < n; j += i) //mark as not prime all multiples of i, smaller than or equal to n
            {
                primes[j] = false;
            }
        }
        i++;
    }
}

void printCriteria(int size, bool* arr) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i])
        {
            cout << i << " ";
        }
    }
}

int main()
{
    cout << "Limit: ";
    int n;
    cin >> n;

    bool* primes = new bool[n + 1];
    for (int i = 0; i < n; i++)
    {
        primes[i] = true;
    }
    allPrimes(n, primes);
    printCriteria(n + 1, primes);

    delete[] primes;
}