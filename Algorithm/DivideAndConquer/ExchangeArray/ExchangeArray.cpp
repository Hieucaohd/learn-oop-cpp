#include <iostream>

using namespace std;

void exchangeArray(int *array, const int &numberElement, const int &numberNeedExchange)
{
	for (int i = 1; i <= numberNeedExchange; i++)
	{
		int takeNumber = array[0];

		for (int j = 0; j < numberElement; j++)
		{
			array[j] = array[j + 1];
		}

		array[numberElement - 1] = takeNumber;
	}
}

int main(int argc, char *argv[])
{
	int *array = new int[7];

	cout << "Nhap mang: " << endl;
	for (int i = 0; i < 7; i++)
	{
		cin >> array[i];
	}
	system("clear");

	cout << "Mang: ";
	for (int i = 0; i < 7; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	exchangeArray(array, 7, 3);

	cout << "Mang: ";
	for (int i = 0; i < 7; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	
	delete [] array;
	return 0;
}
