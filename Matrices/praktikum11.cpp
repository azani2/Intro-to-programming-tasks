#include <iostream>
using namespace std;

//task 1
void init(int* arr, int size) {
    for (size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int arrSum(int* arr, int size) {
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];//*(arr+i)
    }
    return sum;
}


void readArray(int& n, int*& arr) {
    cout << "Size: ";
    cin >> n;
    cout << "Init: ";
    arr = new int[n];
    init(arr, n);
}

void zad1() {
    int n = 0;
    int* arr = nullptr;
    readArray(n, arr);

    cout << "Sum: ";
    cout << arrSum(arr, n);
    delete[] arr;
}



//task 2
void printArr(int n, const int* arr) {
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void zad2() {
    int n;
    cout << "Size: ";
    cin >> n;
    cout << "Init: ";
    int* arr = new int[n];
    int len = (n % 2) ? (n / 2 + 1) : n / 2;
    for (size_t i = 0; i < len; i++)
    {
        cin >> arr[i];
        cin >> arr[n - i - 1];
    }
    printArr(n, arr);
    delete[] arr;
}

//task 3
unsigned int onesCount(int* fakeBoolArr, int size) {
    int res = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (fakeBoolArr[i])
        {
            res++;
        }
    }
    return res;
}

void keepAndCountOnes(int size, int* criteria, int* kept, int* arr) {
    for (size_t i = 0; i < size; i++)
    {
        if (criteria[i])
        {
            *kept = arr[i];
            kept++;
        }
    }

}

void zad3() {
    int n = 0;
    int* arr = nullptr;
    readArray(n, arr);
     
    int* criteria = new int[n]; //not bool because init function works with ints
    cout << "Init: ";

    init(criteria, n);

    int keptCount = onesCount(criteria, n);
    int* kept = new int[keptCount];
    keepAndCountOnes(n, criteria, kept, arr);
    printArr(keptCount, kept);
}

//task 4
void printOddMat(int** matrix, int n, int m) {
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (!(matrix[i][j] % 2))  
            {
                cout << '*' << " ";
                continue;
            }
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void freeMatrix(int** matrix, int n) {
    for (size_t i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void zad4() {
    int n, m;
    cout << "Size: ";
    cin >> n >> m;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
        cout << "Row " << (i + 1) << ": ";
        init(matrix[i], m);
    }

    printOddMat(matrix, n, m);
    freeMatrix(matrix, n);
}

//task 5
int sumAboveMainDiagonal(int** squareMatrix, int n) {
    int lastRow = n - 1;
    int sum = 0;
    for (int i = 0; i < lastRow; i++)
    {
        sum += squareMatrix[i][i + 1];
    }
    return sum;
}

int countOddUnderMainDiagonal(int** squareMatrix, int n) {
    int size = n - 1;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (squareMatrix[i+1][i] % 2)
        {
            count++;
        }
    }
    return count;
}

void oddUnderMainDiagonal(int** squareMatrix, int n, int*& resArr) {
    int resInd = 0;
   for (int i = 1; i < n; i++)
    {
        if (squareMatrix[i][i - 1])
        {
            resArr[resInd] = squareMatrix[i][i - 1];
            resInd++;
        }
    }
}

void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void zad5_1() {
    int n;
    cout << "Size: ";
    cin >> n;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        cout << "Row " << (i + 1) << ": ";
        init(matrix[i], n);
    }
    printMatrix(matrix, n, n);

    //a
    cout << "1) " << sumAboveMainDiagonal(matrix, n) << endl;

    //b no i s arraya na chislata because why not
    int resArrLen = countOddUnderMainDiagonal(matrix, n);
    int* resArr = new int[resArrLen];
    oddUnderMainDiagonal(matrix, n, resArr);
    cout << "2) ";
    printArr(resArrLen, resArr);
    int resArrSum = arrSum(resArr, resArrLen);
    cout << " sum: " << resArrSum;

    delete[] resArr;
    freeMatrix(matrix, n);
}
///////////////

int sumAllEvenAboveMainDiagonal(int** sqrMatrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sum += sqrMatrix[i][j] % 2 ? 0 : sqrMatrix[i][j];
        }
    }
    return sum;
}

int sumAllOddUnderMainDIagonal(int** sqrMatrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum += sqrMatrix[i][j] % 2 ? sqrMatrix[i][j] : 0;
        }
    }
    return sum;
}

int secondDiagonalSquaresSum(int** sqrMatrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += sqrMatrix[i][n - 1 - i] * sqrMatrix[i][n - 1 - i];
    }
    return sum;
}

void zad5_2() {
    int n;
    cout << "Size: ";
    cin >> n;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        cout << "Row " << (i + 1) << ": ";
        init(matrix[i], n);
    }
    printMatrix(matrix, n, n);

    //a
    cout << "1) " << sumAllEvenAboveMainDiagonal(matrix, n) << endl;

    //b
    cout << "2) " << sumAllOddUnderMainDIagonal(matrix, n) << endl;

    //v
    cout << "3) " << secondDiagonalSquaresSum(matrix, n) << endl;

    freeMatrix(matrix, n);
}

int main()
{
    cout << "Zad: ";
    int ch = 0;
    cin >> ch;

    switch (ch)
    {
    case 1:
        zad1();
        break;
    case 2:
        zad2();
        break;
    case 3:
        zad3();
        break;
    case 4:
        zad4();
        break;
    case 5:
        zad5_2();
        cout << "..." << endl;
        zad5_1();
        break;
    default:
        break;
    }


}