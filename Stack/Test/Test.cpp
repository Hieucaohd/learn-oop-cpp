#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	string a;
	a = "hieu";
	switch (a)
	{
		case "hieu":
			cout << "bang hieu" << endl;
			break;
	
		case "phuong":
			cout << "bang phuong" << endl;
			break;
		
		case "huy":
			cout << "bang huy" << endl;
			break;
		
		default:
			cout << "khong bang gi ca." << endl;
	}
	return 0;
}
