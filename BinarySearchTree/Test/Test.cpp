#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int *a;
	int c = 3;
	a = &c;
	cout << "Gia tri cua a la: " << *a << endl;
	cout << endl;

	int *b;
	int e = 4;
	b = &e;
	cout << "Gia tri cua b la: " << *b << endl;
	cout << endl;

	*a = *b;
	cout << "Gia tri cua a la: " << *a << endl;
	cout << "Gia tri cua b la: " << *b << endl;
	cout << endl;

	*a = 100;
	cout << "Gia tri cua a la: " << *a << endl;
	cout << "Gia tri cua b la: " << *b << endl;
	cout << endl;
	return 0;
}
