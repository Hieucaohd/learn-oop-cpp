#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char *argv[])
{
	int number = 123;
    string result;
    ostringstream convert;
    convert << number;
    result = convert.str();
    cout << result;
	return 0;
}
