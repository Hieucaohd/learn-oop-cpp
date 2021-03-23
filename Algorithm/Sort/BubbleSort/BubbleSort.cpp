#include <iostream>

using namespace std;

void BubbleSort(int * array, const int &numberElement)
{
	for (int i = numberElement - 1; i > 0; i--)
	{
		bool isSorter = true;

		for (int k = 0; k < i; k++)
		{
			if (array[k] > array[k + 1])
			{
			    array[k + 1] = array[k] + array[k + 1];
				array[k] = array[k + 1] - array[k];
				array[k + 1] = array[k + 1] - array[k];

				isSorter = false;
			}
		}

		if (isSorter)
		{
			break;
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

	BubbleSort(array, numberElement);

	cout << "Mang: ";
	for (int i = 0; i < numberElement; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	delete [] array;
	return 0;
}
