#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	string a;
	a.push_back('a');
	a.push_back('c');
	a.pop_back();
	cout << a << endl;
	char b = a[a.length() - 1];
	cout << b << endl;
	return 0;
}
