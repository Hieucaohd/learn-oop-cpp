#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int *a;
	int c = 3;
	a = &c;
	int b = 2;
	*a = b;

	*a = 4;
	b = 6;
	cout << *a << endl;
	cout << c << endl;
	cout << "Gia tri cua b la: " << b << endl;
	return 0;
}
