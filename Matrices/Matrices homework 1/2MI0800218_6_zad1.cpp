using namespace std;
#include <iostream>


char** createMatrix(int size, const size_t MAX_SIZE) {
    char** matrix = new char* [size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new char[MAX_SIZE];
    }
    return matrix;
}

void initMatrix(char** matrix, int size) {
    for (int i = 0; i < size; i++)
    {
        std::cin >> matrix[i];
    }
}

void free(char** matrix, int size) {
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool isOdd(int n) {
    return (n & 1);
}

void makeAllZeros(bool* arr, size_t size) {
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

bool isUpperLetter(char c) {
    return (c <= 'Z' && c >= 'A');
}

bool isLowerLetter(char c) {
    return (c <= 'z' && c >= 'a');
}

int getPresentNumber(char c) {
    int n = 0;
    if (isLowerLetter(c))
    {
        n = c - 97;
    }
    else if (isUpperLetter(c))
    {
        n = (c - 65) + 26;
    }
    return n;
}

char wrongPresent(char* bag, bool* criteria) {
    int size = strlen(bag);
    if (isOdd(size) || !size) {
        return '0';
    }

    size_t halfSize = size / 2;
    makeAllZeros(criteria, 52);

    for (int i = 0; i < halfSize; i++)
    {
        criteria[getPresentNumber(bag[i])] = true;
    }

    for (int i = halfSize; i < size; i++)
    {
        if (criteria[getPresentNumber(bag[i])])
        {
            return bag[i];
        }
    }
    return '0';
}

int sumPriorities(char* arr, size_t size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        int priority = getPresentNumber(arr[i]) + 1;
        sum += priority;
    }
    return sum;
}

void print(char* arr, size_t size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << '(' << (i + 1) << ") " << arr[i] << endl;
    }
}

void getGroupIdentifiers(/*char** matrix*/ char matrix[][80]/*za testvane*/, int size, bool* criteria, char* groupIds) {
    for (size_t i = 0; i < size; i += 3)
    {
        int bagsContaining[52] = { 0 };
        size_t bagSize = strlen(matrix[i]);
        for (int j = 0; j < bagSize; j++)
        {
            bagsContaining[getPresentNumber(matrix[i][j])] = 1;
        }

        bagSize = strlen(matrix[i + 1]);
        makeAllZeros(criteria, 52);
        for (int j = 0; j < bagSize; j++)
        {
            if (!criteria[getPresentNumber(matrix[i + 1][j])])
            {
                bagsContaining[getPresentNumber(matrix[i + 1][j])]++;
                criteria[getPresentNumber(matrix[i + 1][j])] = true;;
            }
        }

        bagSize = strlen(matrix[i + 2]);
        makeAllZeros(criteria, 52);
        for (int j = 0; j < bagSize; j++)
        {
            if (!criteria[getPresentNumber(matrix[i + 2][j])])
            {
                bagsContaining[getPresentNumber(matrix[i + 2][j])]++;
                criteria[getPresentNumber(matrix[i + 2][j])] = true;;
            }
            if (bagsContaining[getPresentNumber(matrix[i + 2][j])] == 3)
            {
                groupIds[(i + 2) / 3] = matrix[i + 2][j];
                break;
            }
        }
    }
}

int main()
{
    //cout << ('a' - 97) << endl << ('z' - 97) << endl << ('A' - 65) + 26 << endl << ('Z' - 65) + 26;
    const size_t MAX_BAG_SIZE = 80;
    int c = 6;
    //std::cin >> c;
    //char** bags = createMatrix(c, MAX_BAG_SIZE);
    //initMatrix(bags, c);
    char bags[6][MAX_BAG_SIZE] = { "vJrwpWtwJgWrhcsFMMfFFhFp",
                                    "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
                                    "PmmdzqPrVvPwwTWBwg",
                                    "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
                                    "ttgJtRGJQctTZtZT",
                                    "CrZsJsPPZsGzwwsLwLmpwMDw" };
    bool criteria[52] = { 0 };
    char* wrongPresents = new char[c];

    //A
    for (int i = 0; i < c; i++)
    {
        wrongPresents[i] = wrongPresent(bags[i], criteria);
    }
    cout << "Wrong presents:" << endl;
    print(wrongPresents, c);

    //B
    int mistakesPriorities = sumPriorities(wrongPresents, c);
    std::cout << "Mistakes priorities: " << mistakesPriorities << endl;

    //V
    size_t groupsN = c / 3;
    char* groupIDs = new char[groupsN];
    getGroupIdentifiers(bags, c, criteria, groupIDs);
    cout << "Group IDs:" << endl;
    print(groupIDs, groupsN);


    delete[] groupIDs;
    delete[] wrongPresents;
    //free(bags);
}