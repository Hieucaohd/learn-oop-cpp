#include <iostream>
#include <string>
#include <vector>
#include "Nope/Nope.h"
#include "DynamicSet/DynamicSet.h"
using namespace std;


int main(int argc, char *argv[])
{
	system("clear");
	CDynamicSet *set_1 = new CDynamicSet();
	set_1->insert(5, 5);
	set_1->insert(2, 2);
	set_1->insert(3, 3);
	set_1->insert(7, 7);
	set_1->insert(6, 6);
	set_1->insert(11, 11);
	set_1->insert(8, 8);
	set_1->insert(9, 9);
	set_1->insert(12, 12);
	typeOfData a;

	CDynamicSet *set_2 = new CDynamicSet(set_1);
	set_2->insert(100, 100);

	set_2->search(12, a);
	cout << a << endl;

	if (set_2->search(100, a))
	/* Neu tim thay.*/
	{
	    cout << "Tim thay." << endl;
	}
	else
	/* Neu khong tim thay.*/
	{
		cout << "Khong tim thay." << endl;
	}

	set_2->deleteElementByKey(100);
	if (set_2->search(100, a))
	/* Neu tim thay.*/
	{
	    cout << "Tim thay." << endl;
	}
	else
	/* Neu khong tim thay.*/
	{
		cout << "Khong tim thay." << endl;
	}
	return 0;
}
