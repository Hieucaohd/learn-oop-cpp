#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string xau;
	char a = 'a';
	char b = 'b';

	xau.push_back(a);
	xau.push_back(b);

	xau += "hieu";
	cout << xau << endl;
	return 0;
}
