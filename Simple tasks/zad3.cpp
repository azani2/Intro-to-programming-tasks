#include <iostream>
using namespace std;

bool sameDot(int x1, int y1, int x2, int y2) {
    return (x1 == x2 && y1 == y2);
}
double distanceBetweenTwoDots(int x1, int y1, int x2, int y2) {
    int a = x1 - x2;
    int b = y1 - y2;
    return sqrt(a * a + b * b);
}

bool triangleExists(double a, double b, double c) {
    return (a < (b + c) && b < (a + c) && c < (a + b));
}

double triangleP(double a, double b, double c) {
    if (triangleExists)
        return a + b + c;
    return -1;
}

double triangleP(int x1, int y1, int x2, int y2, int x3, int y3) {
    if (sameDot(x1, y1, x2, y2) || sameDot(x1, y1, x3, y3) || sameDot(x3, y3, x2, y2))
        return -1;
    double a = distanceBetweenTwoDots(x1, y1, x2, y2);
    double b = distanceBetweenTwoDots(x1, y1, x3, y3);
    double c = distanceBetweenTwoDots(x2, y2, x3, y3);
    return triangleP(a, b, c);
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << triangleP(x1, y1, x2, y2, x3, y3);
}