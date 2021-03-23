#include <iostream>

using namespace std;

int * findChildArray(int *array, const int &numberElement, int &count)
{
	int *childArray = new int[numberElement];
	childArray[0] = array[0];

	for (int i = 1; i < numberElement; i++)
	/* Xet tung phan tu bat dau tu vi tri 1 trong mang array tro di.*/
	{
		if (array[i] >= childArray[count])
		/* Neu phan tu dang xet lon hon phan tu cuoi cung cua mang con.*/
		{
			/* Thi ta them phan tu do vao mang con.*/
		 	count ++;
		 	childArray[count] = array[i];	
		}
		else if (array[i] < childArray[count])
		/* Neu phan tu dang xet nho hon phan tu cuoi cung cua mang con.*/
		{
			if (count == 0)
			/* Neu mang con luc do chi co 1 phan tu.*/
			{
				/* Thi ta thay the phan tu trong mang con bang phan tu dang xet.*/
			    childArray[count] = array[i];
			}
			else 
			/* Neu mang con luc do co 2 phan tu tro len.*/
			{
				if ( (array[i] > childArray[count - 1]) && (array[i] < childArray[count]) )
				{
					/* Neu phan tu dang xet lon hon phan tu gan cuoi cung trong mang con
					 * Dong thoi nho hon phan tu cuoi cung trong mang con.*/

					/* Thi ta loai phan tu cuoi cung trong mang con ra va thay the bang phan tu dang xet.*/
					childArray[count] = array[i];
				}
			}
		}
	}

	return childArray;
}

int main(int argc, char *argv[])
{
	int *array = new int[8];

	cout << "Nhap mang: " << endl;
	for (int i = 0; i < 8; i++)
	{
		cin >> array[i];
	}

	system("clear");

	cout << "Mang: ";
	for (int i = 0; i < 8; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	int count = 0;
	int * childArray = findChildArray(array, 8, count);

	cout << "Mang con: ";
	for (int i = 0; i < count + 1; i++)
	{
		cout << childArray[i] << " ";
	}
	cout << endl;

	delete [] array;
	delete [] childArray;
	return 0;
}
