#include <iostream>
using namespace std;

bool isDigit(char c) {
    return (c >= '1' && c <= '9');
}

int toDigitOrExc(char c) {
    if (isDigit(c))
        return (int)c - 48;
    return -1;
}
int main()
{
    char c;
    cin >> c;
    cout << toDigitOrExc(c);
}
