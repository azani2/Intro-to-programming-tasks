#include <iostream>
using namespace std;

bool hasOddDigitsOnly(const char* number) {
    while (*number) {
        if (!((*number - 0) % 2))
        {
            return false;
        }
        number++;
    }
    return true;
}

int main()
{
    const size_t MAX_SIZE = 100;
    char number[MAX_SIZE];
    cin >> number;
    cout << hasOddDigitsOnly(number);
}