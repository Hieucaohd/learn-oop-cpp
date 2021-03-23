#include <iostream>

using namespace std;

/* Sap xep tu be toi lon.*/
void mergeArray(int * array_1, int * array_2, int * arrayResult, int numberElement_1, int numberElement_2, int &count, int index_1, int index_2)
{
	if ( (index_1 <= numberElement_1 - 1) && (index_2 <= numberElement_2 - 1) )
	/* Neu 2 chi so ta xet van dang nam trong 2 mang.*/
	{
		if (array_1[index_1] < array_2[index_2])
		/* Neu phan tu dang xet o mang 1 nho hon phan tu dang xet o mang 2.*/
		{
			/* Thi ta them phan tu o mang 1 vao mang ket qua va xet phan tu ke tiep o mang 1.
			 * Con phan tu o mang 2 thi giu nguyen.*/
			arrayResult[count] = array_1[index_1];
			count ++;
			mergeArray(array_1, array_2, arrayResult, numberElement_1, numberElement_2, count, index_1 + 1, index_2);
		}
		else if (array_1[index_1] > array_2[index_2])
		/* Neu phan tu dang xet o mang 2 nho hon phan tu dang xet o mang 1.*/
		{
			/* Thi ta them phan tu o mang 2 vao mang ket qua va xet phan tu ke tiep o mang 2.
			 * Con phan tu o mang 1 thi giu nguyen.*/
			arrayResult[count] = array_2[index_2];
			count ++;
			mergeArray(array_1, array_2, arrayResult, numberElement_1, numberElement_2, count, index_1, index_2 + 1);
		}
		else if (array_1[index_1] == array_2[index_2])
		/* Neu phan tu dang xet o ca 2 mang bang nhau.*/
		{
			/* Thi ta them phan tu do vao mang ket qua, dong thoi xet phan tu ke tiep o ca 
			 * 2 mang.*/
			arrayResult[count] = array_1[index_1];
			count ++;
			mergeArray(array_1, array_2, arrayResult, numberElement_1, numberElement_2, count, index_1 + 1, index_2 + 1);
		}
	}
	else if (index_1 > numberElement_1 - 1)
	/* Neu da xet het cac phan tu o mang 1.*/
	{
		/* Thi ta xem phan con lai cua mang 2 vao mang ket qua.*/
		for (int i = index_2; i < numberElement_2; i++)
		{
			arrayResult[count] = array_2[i];
			count ++;
		}
	}
	else if (index_2 > numberElement_2 - 1)
	/* Neu da xet het cac phan tu o mang 2.*/
	{
		/* Thi ta xem phan con lai cua mang 1 vao mang ket qua.*/
		for (int i = index_1; i < numberElement_1; i++)
		{
			arrayResult[count] = array_1[i];
			count ++;
		}
	}
}

void inputArray(int * array, const int &numberElement)
{
	cout << "Nhap mang: " << endl;
	for (int i = 0; i < numberElement; i++)
	{
		cin >> array[i];
	}

	system("clear");

}

void outputArray(int * array, const int &numberElement)
{
	cout << "Mang: ";
	for (int i = 0; i < numberElement; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void thu()
{
	int * array_1 = new int[4];
	int * array_2 = new int[3];
	int * arrayResult = new int[7];

	inputArray(array_1, 4);
	inputArray(array_2, 3);
	outputArray(array_1, 4);
	outputArray(array_2, 3);

	int count = 0;
	mergeArray(array_1, array_2, arrayResult, 4, 3, count, 0, 0);

	outputArray(arrayResult, count);

	delete [] array_1;
	delete [] array_2;
	delete [] arrayResult;
}

int main(int argc, char *argv[])
{
	thu();
	return 0;
}
