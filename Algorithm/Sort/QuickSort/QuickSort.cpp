#include <iostream>

using namespace std;

void swap(int * array, const int &index1, const int &index2)
{
	array[index1] = array[index1] + array[index2];
	array[index2] = array[index1] - array[index2];
	array[index1] = array[index1] - array[index2];
}

void Partition(int * array, int start, int end, int &middle)
{
	int left = start + 1;
	int right = end;

	do
	{
		while ( (left <= right) && (array[left] <= array[start]) )
		/* Chay cac chi so ben trai cho toi khi gap phan tu > moc.*/
		{
			left ++;
		}

		while ( (left <= right) && (array[right] > array[start]) )
		/* Chay cac chi so ben phai cho toi khi gap phan tu <= moc.*/
		{
			right --;
		}
		
		if (left <= right)
		/* Neu left chua vuot qua right.*/
		{
			swap(array, left, right);

			left ++;
			right --;
		}
	}
	while (left <= right);

	swap(array, start, right);

	middle = right;
}

void QuickSort(int * array, int start, int end)
{
	if (start < end)
	{
	   int middle; 
	   Partition(array, start, end, middle);

	   if (start < middle)
	   {
	       QuickSort(array, start, middle - 1);
	   }

	   if (middle + 1 < end)
	   {
	       QuickSort(array, middle + 1, end);
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

	QuickSort(array, 0, numberElement - 1);

	cout << "Mang: ";
	for (int i = 0; i < numberElement; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	delete [] array;
	return 0;
}
