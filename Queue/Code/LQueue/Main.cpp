#include <iostream>
#include <string>
#include "Queue/Queue.h"

using namespace std;

int main(int argc, char *argv[])
{
	CQueue queue1;
	queue1.enQueue("hieu");
	cout << queue1.deQueue() << endl;
	return 0;
}
