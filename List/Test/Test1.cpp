#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	system("clear");
	int *p = new int;
	*p = 5;
	int *a;
	a = p;
	cout << "Truoc khi lam gi do: " << endl;
	cout << "p = " << *p << endl;
	cout << "Dia chi cua p = " << p << endl;
	cout << "a = " << *a << endl;
	cout << "Dia chi cua a = " << a << endl;
	cout << endl;

	p = new int;
	*p = 6;
	cout << "Sau khi lam gi do: " << endl;
	cout << "p = " << *p << endl;
	cout << "Dia chi cua p = " << p << endl;
	cout << "a = " << *a << endl;
	cout << "Dia chi cua a = " << a << endl;


	delete a;
	delete p;
	return 0;
}
