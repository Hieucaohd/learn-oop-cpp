#include <iostream>
#include <string>
#include <vector>
#include "Stack/Stack.h"
#include "CheckParentheses/CheckParentheses.h"
#include "Calculate/Calculate.h"
using namespace std;

void inputInfix(string *infix, int number_of_elements)
{
	/* Nhap bieu thuc infix: */
	cout << "Nhap bieu thuc infix: ";
	for (int i = 0; i < number_of_elements; i++)
	{
		cin >> infix[i];
	}
}

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

void kiemTraDauNgoacDon()
{
	/* Kiem tra dau ngoac co thoa man hay khong.*/
	/* Khoi tao mang cac dau ngoac.*/
	int size_of_array; // kich thuoc cua mang.
	cout << "Nhap kich thuoc cua mang array: "; 
	cin >> size_of_array;
	string *array = new string[size_of_array]; // mang cac dau ngoac.

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


	cout << endl;
	delete [] array;
}

void infixAndPostfix()
{
	int number_of_elements; // so luong cac phan tu cua infix.
	cout << "Nhap so luong cac phan tu cua infix: ";
	cin >> number_of_elements;

	string *infix= new string[number_of_elements];

	/* Nhap bieu thuc infix: */
	inputInfix(infix, number_of_elements);

	/* Xuat bieu thuc infix: */
	outputInfix(infix, number_of_elements);

	/* Chuyen infix thanh postfix: */
	vector<string> postfix = changeInfixToPostfix(infix, number_of_elements);

	/* In ra bieu thuc postfix: */
	outputPostfix(postfix);
}

int main(int argc, char *argv[])
{
	infixAndPostfix();
	return 0;
}
