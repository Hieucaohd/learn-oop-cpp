#include <iostream>
#include <string>
#include <vector>

using namespace std;

void maxMin(int start, int end, int &max, int &min, int *array)
{
	if (start == end)
	/* Neu mang chi co 1 phan tu.*/
	{
		max = min = array[start];
	}
	else if ( (start + 1) == end )
	/* Neu mang chi co 2 phan tu.*/
	{
		if (array[start] <= array[end])
		{
			min = array[start];
			max = array[end];
		}
		else
		{
			min = array[end];
			max = array[start];
		}
	}
	else
	/* Neu co the chia doi mang.*/
	{
		/* Lay chi so o giua cua mang.*/
		int mid = (start + end) / 2;

		int max1, min1, max2, min2;

		/* Duyet mang ben trai mid.*/
		maxMin(start, mid, max1, min1, array);

		/* Duyet mang ben phai mid.*/
		maxMin(mid + 1, end, max2, min2, array);

		/* Xet phan tu lon nhat.*/
		if (max1 > max2)
		/* Neu phan tu lon nhat nam o ben mang ben trai mid.*/
		{
		 	max = max1;   
		}
		else
		/* Neu nguoc lai, phan tu lon nhat nam o ben mang ben phai mid.*/
		{
			max = max2;
		}
		
		/* Xet phan tu nho nhat.*/
		if (min1 < min2)
		/* Neu phan tu nho nhat nam o ben mang ben trai mid.*/
		{
			min = min1;
		}
		else
		/* Neu nguoc lai, phan tu nho nhat nam o ben mang ben phai mid.*/
		{
			min = min2;
		}
	}
}

int main(int argc, char *argv[])
{
	int number_element;
	cout << "Nhap so luong phan tu cua mang: "; cin >> number_element;

	int *array = new int[number_element];
	for (int i = 0; i < number_element; i++)
	{
		cin >> array[i];
	}
	system("clear");

	cout << "Mang: ";
	for (int i = 0; i < number_element; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	int max, min;
	maxMin(0, number_element - 1, max, min, array);

	cout << "Phan tu lon nhat la: " << max << endl;
	cout << "Phan tu nho nhat la: " << min << endl;

	delete [] array;
	return 0;
}


