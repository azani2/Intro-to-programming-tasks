#include <iostream>
using namespace std;

void freeMatrix(int n, int** matrix) {
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void minMaxCoordinates(int** pointsMatrix, int pointsNumber,
                        int& minX, int& maxX, int& minY, int& maxY) {
    minX = maxX = pointsMatrix[0][0]; //first x
    minY = maxY = pointsMatrix[0][1]; //first y
    for (int i = 1; i < pointsNumber; i++)
    {
        if (pointsMatrix[i][0] >= maxX)
        {
            maxX = pointsMatrix[i][0];
        }
        if (pointsMatrix[i][0] < minX)
        {
            minX = pointsMatrix[i][0];
        }
        if (pointsMatrix[i][1] >= maxY)
        {
            maxY = pointsMatrix[i][1];
        }
        if (pointsMatrix[i][1] < minY)
        {
            minY = pointsMatrix[i][1];
        }
    }
}

int main()
{
    int pointsNumber = 0;
    cout << "Points number: ";
    cin >> pointsNumber;

    int** pointsCoordinates = new int*[pointsNumber];

    for (int i = 0; i < pointsNumber; i++)
    {
        pointsCoordinates[i] = new int[2];
        cout << "Point " << 1 + i << ": ";
        cin >> pointsCoordinates[i][0] >> pointsCoordinates[i][1]; // i 0 e xi, i 1 e yi
    }
  
    int maxX, maxY, minX, minY;
    maxX = maxY = minX = minY = 0;
    minMaxCoordinates(pointsCoordinates, pointsNumber, minX, maxX, minY, maxY);
    
    int squareA = 0;
    int dY = maxY - minY;
    int dX = maxX - minX;
    squareA = dY >= dX ? dY : dX;

    int squareV = squareA * squareA;
    cout << "Square V: " << squareV;

    freeMatrix(pointsNumber, pointsCoordinates);
}
