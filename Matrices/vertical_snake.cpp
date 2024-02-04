#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int lastPrinted;
    
    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ';
        lastPrinted = i;
        for (int j = 2; j <= n + 1; j++)
        {
            if (lastPrinted % n == 0) {
                lastPrinted = lastPrinted + 1;
            }
            else
            {
                if (j % 2 == 1)
                {
                    lastPrinted += 2 * i - 1;
                }
                else
                {
hym,                    lastPrinted = j*n - lastPrinted + 1;
                }
            }
            cout << lastPrinted << ' ';
        }
        cout << endl;
    }
}