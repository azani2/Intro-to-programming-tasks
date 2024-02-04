#include <iostream>
using namespace std;

void addToArray(int arr[], size_t length, const size_t SIZE) {
    for (size_t i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
    //for (size_t i = length; i < SIZE; i++)
    //{
    //    arr[i] = 0;//всички въведени елементи са > 1 по условие
    //}
}

bool isPrime(int n) {
    double sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; i+= 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void fillPrimalityRef(const int arr[], size_t length, bool reference[]) {
    for (size_t i = 0; i < length; i++)
    {
        reference[i] = isPrime(arr[i]);
    }
}

unsigned int primeNumbersInArr(size_t length, bool reference[]) {
    int count = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (reference[i])
            count++;
    }
    return count;
}

void countCriteria2Problems(size_t length, size_t index/*for comparison*/, bool reference[],
                                            const int originalArr[], unsigned int& problemsCount) {
    for (size_t j = 1; j <= length - index - 1; j++)
    {
        if (reference[index + j] && originalArr[index] > originalArr[index + j])
            problemsCount++;
    }
}

unsigned int countAllProblems(const int arr[], size_t length, bool reference[]) {
    unsigned int ones = primeNumbersInArr(length, reference);
    unsigned int zeroes = length - ones;
    unsigned int problemsCount = 0;

    if (!reference[0])
        zeroes--;

    for (size_t i = 0; i < length - 1; i++)
    {
        if (reference[i]) {
            problemsCount += zeroes;

            //criteria2problems with arr[i]
            countCriteria2Problems(length, i, reference, arr, problemsCount);
        } 
        if (!reference[i + 1])
            zeroes--;
    }

    return problemsCount;
}

bool validInput(size_t enteredLength, const size_t MAX_SIZE) {
    return (enteredLength <= MAX_SIZE);
}

int main()
{
    const size_t MAX_SIZE = 1024;
    int arr[MAX_SIZE];

    size_t length;
    cout << "length > ";
    cin >> length;

    if (!validInput(length, MAX_SIZE))
        return 1;

    addToArray(arr, length, MAX_SIZE);

    bool primalityReference[MAX_SIZE];
    fillPrimalityRef(arr, length, primalityReference);

    int res = countAllProblems(arr, length, primalityReference);
    cout << res;

    return 0;
}