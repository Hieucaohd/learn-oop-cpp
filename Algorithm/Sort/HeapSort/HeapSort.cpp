#include <iostream>

using namespace std;

void shiftDown(int * array, int numberElement, int index)
{
	int take_data = array[index]; // bien take_data luu du lieu o dinh index.
	int parent = index; // bien parent luu lai chi so cua dinh cha.
	int child = 2 * parent + 1; // bien child luu lai chi so cua dinh con trai.

	while (child <= numberElement - 1)
	/* Khi ma phan tu dang xet van dang o trong cay.*/
	{
		int right = child + 1; // bien right luu lai chi so cua dinh con phai.

		if (right <= numberElement - 1)
		/* Kiem tra xem chi so cua dinh con phai co ton tai hay khong.*/
		{
		    if (array[right] < array[child])
		    /* Neu dinh con phai co gia tri uu tien nho hon dinh con trai.*/
		    {
				/* Thi ta xet dinh con phai.*/
		        child = right;
		    }
		}

		if (take_data > array[child])
		/* Neu gia tri uu tien cua take_data lon hon dinh con.*/
		{
			/* Hoan doi du lieu o dinh cha voi dinh con.*/
			array[parent] = array[child]; 		   
			array[child] = take_data;

			/* Di xuong nhanh cay con de xet tiep.*/
			parent = child;
			child = 2 * parent + 1;
		}
		else
		/* Neu nho hon.*/
		{
			/* Thi thoat vong lap va ket thuc.*/
			break;
		}

	} // end while.
}

void swap(int * array, const int &index1, const int &index2)
{
	array[index1] = array[index1] + array[index2];
	array[index2] = array[index1] - array[index2];
	array[index1] = array[index1] - array[index2];
}

void HeapSort(int * array, const int numberElement)
{
	/* Ta se xet cac phan tu tu vi tri (phan nguyen cua)(n/2 - 1) (voi n la so 
	 * luong phan tu trong hang uu tien) den vi tri 0.*/
	int from_vertex = (int)(numberElement/2.0 - 1);

	for (int i = from_vertex; i >= 0; i--)
	{
		/* Duyet cac phan tu i = from_vertex, ... , 2, 1, 0.
		 * Dua chung xuong vi tri thich hop.
		 * Ta se thu duoc cay thu tu bo phan hoan chinh.
		 * */
		shiftDown(array, numberElement, i);
	}

	for (int i = numberElement - 1; i >= 1; i--)
	{
		swap(array, 0, i);
		shiftDown(array, i - 1, 0);
	}

	swap(array, 0, 1);
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

	HeapSort(array, numberElement);

	cout << "Mang: ";
	for (int i = 0; i < numberElement; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	delete [] array;
	return 0;
}
