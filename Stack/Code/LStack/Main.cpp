#include <iostream>
#include "Stack/Stack.h"
#include "Nope/Nope.h"

using namespace std;

int main(int argc, char *argv[])
{
	system("clear");
	CStack stack1;
	stack1.push(1);
	cout << stack1.pop() << endl;

	if (stack1.isStackEmpty())
	/* Neu ngan xep rong.*/
	{
	    cout << "Rong." << endl;
	}
	else
	/*comment*/
	{
		cout << "Khong rong." << endl;
	}
	
	stack1.push(2);
	cout << stack1.getTop() << endl;
	if (stack1.isStackEmpty())
	/* Neu ngan xep rong.*/
	{
	    cout << "Rong." << endl;
	}
	else
	/*comment*/
	{
		cout << "Khong rong." << endl;
	}
	return 0;
}
