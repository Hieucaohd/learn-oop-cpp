#include <iostream>
#include <string>
#include "Stack/Stack.h"
#include "CheckParentheses/CheckParentheses.h"
#include "Calculate/Calculate.h"
using namespace std;

void inputArray(string *array_parameter, int size_of_array)
{
	/* Nhap mang array_parameter voi kich thuoc size_of_array.*/
	for (int i = 0; i < size_of_array; i++)
	{
		cout << "Nhap phan tu thu "<< i << ": ";
		cin >> array_parameter[i];
	}
}

void outputArray(string *array_parameter, int size_of_array)
{
	/* Xuat ra man hinh cac phan tu cua mang array_parameter
	 * voi kich thuoc size_of_array.
	 * */
	cout << "Mang: ";	
	for (int i = 0; i < size_of_array; i++)
	{
		cout << array_parameter[i] << " ";
	}

	cout << endl;
}

int main(int argc, char *argv[])
{
	int size_of_array;
	cout << "Nhap kich thuoc cua mang array: "; cin >> size_of_array;
	string *array = new string[size_of_array];

	/* Nhap mang: */
	inputArray(array, size_of_array);

	/* Xuat mang: */
	outputArray(array, size_of_array);

	/* Kiem tra dau ngoac.*/
	if (checkParentheses(array, size_of_array))
	/* Neu dau ngoac thoa man.*/
	{
	    cout << "Hop le." << endl;
	}
	else
	/* Neu dau ngoac khong thoa man.*/
	{
		cout << "Khong hop le." << endl;
	}
	

	delete [] array;
	return 0;
}
