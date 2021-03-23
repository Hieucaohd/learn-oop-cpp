#include <iostream>

using namespace std;

void SelectionSort(int *array, const int &numberElement)
{
	for (int i = 0; i < numberElement - 1; i++)
	{
		for (int j = i + 1; j < numberElement; j++)
		{
			if (array[j] <= array[i])
			{
			    array[i] = array[j] + array[i];
				array[j] = array[i] - array[j];
				array[i] = array[i] - array[j];
			}
			
		}
	}
}

int main(int argc, char *argv[])
{
	int numberElement;
	cout << "Nhap so luong phan tu: "; cin >> numberElement;

	int * array = new int [numberElement];

	cout << "Nhap mang: " << endl;
	for (int i = 0; i < numberElement; i++)
	{
		cin >> array[i];
	}
	system("clear");

	cout << "Mang: ";
	for (int i = 0; i < numberElement; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	SelectionSort(array, numberElement);

	cout << "Mang: ";
	for (int i = 0; i < numberElement; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	delete [] array;
	return 0;
}
