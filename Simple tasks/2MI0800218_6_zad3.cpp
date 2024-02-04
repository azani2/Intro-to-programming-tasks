#include <iostream>
#include <iomanip>
using namespace std;

void enterCarData(int arr[], unsigned int size) {
    int iterations = 2 * size;
    for (int i = 0; i < iterations; i += 2)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = x;
        arr[i + 1] = y;
    }
}

int distancePassed(int arr[], int size) {
    int iterations = size * 2;
    int prevX = arr[0];
    int prevY = arr[1];
    double dist = 0;
    for (int i = 2; i < iterations; i += 2)
    {
        int subsX = arr[i] - prevX;
        int subsY = arr[i + 1] - prevY;
        dist += sqrt(subsX * subsX + subsY * subsY);
        prevX = arr[i];
        prevY = arr[i + 1];
    }
    return dist;
}

bool validInput(int a) {
    return !(a <= 0 || a > 1024);
}

int main()
{
    int size1, size2;
    const int MAX_SIZE = 2048;
    int car1Data[MAX_SIZE];
    int car2Data[MAX_SIZE];
    cout << "size1 > ";
    cin >> size1;
    if (!validInput(size1)) {
        cout << "Size must be between 1 an 1024.";
        return 0;
    }
    cout << "size2 > ";
    cin >> size2;
    if (!validInput(size2)) {
        cout << "Size must be between 1 an 1024.";
        return 0;
    }
    enterCarData(car1Data, size1);
    enterCarData(car2Data, size2);
    double distanceCar1 = distancePassed(car1Data, size1);
    double distanceCar2 = distancePassed(car2Data, size2);
    
    if (distanceCar1 == distanceCar2) {
        cout << "true\n";
        cout << setprecision(2);
        cout << fixed << showpoint << distanceCar1;
        return 0;
    } 
    cout << false;
    return 0;
}
