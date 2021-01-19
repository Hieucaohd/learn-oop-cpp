#include <iostream>
#include <string>
#include <vector>
#include "Nope/Nope.h"
#include "DynamicSet/DynamicSet.h"
using namespace std;

void thu()
{
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
}


int main(int argc, char *argv[])
{
	system("clear");
	CDynamicSet set_1;
	typeOfData data;
	typeOfKey key;
	set_1.insert(data = 1, key = 2);
	set_1.insert(data = 3, key = 6);
	set_1.insert(data = 5, key = 8);
	set_1.insert(data = 4, key = 0);
	set_1.insert(data = 44, key = 23);
	set_1.insert(data = 22, key = 28);

	return 0;
}
