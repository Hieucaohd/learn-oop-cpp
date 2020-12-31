#include <iostream>
#include "Dlist/Dlist.h"
#include "Term/Term.h"
#include "DlistIterator/DlistIterator.h"
#include "Poly/Poly.h"
using namespace std;

int main(int argc, char *argv[])
{
	system("clear");
	CPoly p1, p2;

	int numbers_p1;
	cout << "Nhap bac cua da thuc p1: "; cin >> numbers_p1;
	p1.inputPoly(numbers_p1);
	p1.outputPoly();

	int numbers_p2;
	cout << "Nhap bac cua da thuc p1: "; cin >> numbers_p2;
	p2.inputPoly(numbers_p2);
	p2.outputPoly();

	CPoly p3 = p1 + p2;
	cout << "Tong cua da thuc p1 + p2 la: ";
	p3.outputPoly();
	return 0;
}
