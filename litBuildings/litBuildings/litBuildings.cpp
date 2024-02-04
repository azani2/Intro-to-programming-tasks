using namespace std;
#include <iostream>

int max(const int arr[], int size) {
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

void free(int** matrix, int size) {
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int** createMatrix(int n, int m) {
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}
	return matrix;
}

void fillImg(int** matrix, int n, int m, int* buildingHeights, int* lightHeight) {
	for (int i = 0; i < n; i++)//0- light, 1- building, 3-air
	{
		matrix[0][i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		int currenHeight = n - i - 1;
		for (int j = 0; j < m; j++)
		{
			if (buildingHeights[j] < currenHeight && lightHeight[j] > currenHeight)
			{
				matrix[i][j] = 3;
			}
			else if (lightHeight[j] > currenHeight)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = 0;
			}
			if (j > 0 && matrix[i][j] == 1 && matrix[i][j - 1] == 0)
			{
				matrix[i][j] = 4;
			}
		}
	}
}

void printImg(int** matrix, int n, int m) {
	int r = n - 1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c = '0';
			switch (matrix[i][j])
			{
			case 0:
				c = '*';
				break;
			case 1:
				c = 'O';
				break;
			case 3:
				c = '~';
				break;
			case 4:
				c = '0';
				break;
			default:
				break;
			}
			cout << " " << c << " ";
		}
		cout << endl;
	}
}

int main()
{
	int buildingsN = 13;
	//cin >> buildingsN;
	buildingsN = 13;//za testvane
	int lightHeight[13];
	//int* buildingHeights = new int[buildingsN];
	int buildingHeights[13] = { 4, 1, 3, 6, 2, 4, 2, 5, 4, 2, 6, 0, 0 };

	/*for (int i = 0; i < buildingsN; i++)
	{
		cin >> buildingHeights[i];
	}*///za testvane
	lightHeight[0] = 1 + buildingHeights[0];

	int litFloors = 0;
	for (int i = 1; i < buildingsN; i++)
	{
		int supposedLH = lightHeight[i - 1] - 1;
		if (supposedLH <= buildingHeights[i])
		{
			lightHeight[i] = buildingHeights[i] + 1;
		}
		else
		{
			lightHeight[i] = supposedLH;
		}

		if (buildingHeights[i] > lightHeight[i - 1]) {
			litFloors += buildingHeights[i] - lightHeight[i - 1] + 1;
		}
	}

	cout << "Lit floors: " << litFloors << endl;
	int imgHeight = 2 + max(buildingHeights, buildingsN);
	int** image = createMatrix(imgHeight, buildingsN);


	//B
	fillImg(image, imgHeight, buildingsN, buildingHeights, lightHeight);
	printImg(image, imgHeight, buildingsN);

	cout << endl << "Lit floors are 0, light is *, dark floors are O and air is ~~~~~~~~~" << endl;

	free(image, imgHeight);
	//delete[] lightHeight; zaradi testovete sa v komentar
	//delete[] buildingHeights;
}