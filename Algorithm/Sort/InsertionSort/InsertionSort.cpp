#include <iostream>

using namespace std;

void InsertionSort(int * array, const int &numberElement)
{
	for (int i = 1; i < numberElement; i++)
	{
		int k = i;
		while (k > 0)
		/*comment*/
		{
			if (array[k] < array[k - 1])
			/*comment*/
			{
			    array[k] = array[k] + array[k - 1];
				array[k - 1] = array[k] - array[k - 1];
				array[k] = array[k] - array[k - 1];

				k --;
			}
			else
			/*comment*/
			{
				break;
			}
		} // End while.
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

	InsertionSort(array, numberElement);

	cout << "Mang: ";
	for (int i = 0; i < numberElement; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	delete [] array;
	return 0;
}
