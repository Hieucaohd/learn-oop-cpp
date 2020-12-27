#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string convertIntNumberToStringNumber(int number)
{
	switch (number)
	{
		case 0:
			return "0";
			break;
	
		case 1:
			return "1";
			break;
		
		case 2:
			return "2";
			break;
		
		case 3:
			return "3";
			break;		

		case 4:
			return "4";
			break;		

		case 5:
			return "5";
			break;		

		case 6:
			return "6";
			break;		

		case 7:
			return "7";
			break;		

		case 8:
			return "8";
			break;		

		case 9:
			return "9";
			break;		
	}
}

string toString(int number)
{
	string result;
	if (number == 0)
	{
	 	return "0";   
	}
	
	while (number != 0)
	{
		result += convertIntNumberToStringNumber(number % 10);
		number /= 10;
	}

	string final_result;

	for (int i = result.length() - 1; i >= 0; i--)
	{
		final_result += result[i];
	}
	return final_result;
}

int main(int argc, char *argv[])
{
	string a = toString(100);
	cout << a << endl;
	return 0;
}
