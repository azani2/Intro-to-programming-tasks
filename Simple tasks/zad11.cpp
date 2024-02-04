#include <iostream>
using namespace std;

bool isLowercaseLetter(char c) {
    return (c >= 'a' && c <= 'z');
}

char toUpper(char c) {
    if (isLowercaseLetter(c))
        return c - 32;
    else
        return c;
}

int main()
{
    char c;
    cin >> c;
    cout << toUpper(c);
}
