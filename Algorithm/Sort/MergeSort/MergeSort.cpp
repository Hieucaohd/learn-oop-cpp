#include <iostream>

using namespace std;

void Merge(int * array, int start, int middle, int end)
{
	int runLeft = start; // bien chay de chay cac chi so cua mang ben trai.
	int runRight = middle + 1; // bien chay de chay cac chi so cua mang ben phai.

	/* Mang de luu 2 mang sau khi merge.*/
	int numberElement = (end - start) / 1 + 1;
	int * arrayMerged = new int [numberElement];

	int count = 0; // bien chay de chay cac chi so cua arrayMerge.

	while ( (runLeft <= middle) && (runRight <= end) )
	/* Ta xet dong thoi cac phan tu o 2 mang ben trai va ben phai.*/
	{
		if (array[runLeft] < array[runRight])
		/* Neu phan tu dang xet cua mang ben trai nho hon ben phai.*/
		{
			/* Thi them phan tu do vao arrayMerge.*/
		    arrayMerged[count] = array[runLeft];
			count ++;
			runLeft ++; // xet phan tu ke tiep cua mang ben trai va giu nguyen phan tu o mang ben phai.
		}
		else
		/* Neu phan tu dang xet cua mang ben phai nho hon ben trai.*/
		{
			/* Thi them phan tu do vao arrayMerge.*/
			arrayMerged[count] = array[runRight];
			count ++;
			runRight ++; // xet phan tu ke tiep cua mang ben phai va giu nguyen phan tu o mang ben trai.
		}
	} // End while.

	while ( runLeft <= middle )
	/* Lay cac phan tu con lai cua mang ben trai chua xet.*/
	{
		arrayMerged[count] = array[runLeft];
		count ++;
		runLeft ++;
	} // End while.
	
	while ( runRight <= end )
	/* Lay cac phan tu con lai cua mang ben phai chua xet.*/
	{
		arrayMerged[count] = array[runRight];
		count ++;
		runRight ++;
	} // End while.

	/* Cuoi cung sao chep cac phan tu tu arrayMerge sang array.*/
	int index = start;
	for (int i = 0; i < count; i++)
	{
		array[index] = arrayMerged[i];
		index ++;
	}
	
	delete [] arrayMerged;
}

void MergeSort(int * array, int start, int end)
{
	if (start < end)
	{
	 	int middle = (start + end) / 2;   

		MergeSort(array, start, middle);
		MergeSort(array, middle + 1, end);
		Merge(array, start, middle, end);
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

	MergeSort(array, 0, numberElement - 1);

	cout << "Mang: ";
	for (int i = 0; i < numberElement; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	delete [] array;

	return 0;
}
