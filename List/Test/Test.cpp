#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int size = 1;
	int number = 3;
	while (number >= size)
	{
		size = size + 1;
	}	
	cout << size << endl;
	return 0;
}
