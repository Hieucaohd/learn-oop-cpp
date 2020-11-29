#include <iostream>
#include "Dlist/Dlist.h"
#include "Term/Term.h"
#include "Dlist/DlistIterator/DlistIterator.h"
using namespace std;

int main(int argc, char *argv[])
{
	system("clear");
	CTerm t1(4,4);
	CTerm t2(6,66);
	CTerm t3(192,2);
	CDlist d(3);
	CDlistIterator iter_D(d);

	d.inputDlist(3);
	cout << "\n\n\t\t truoc khi lam gi do: " << endl;
	d.outputDlist();
	
	iter_D.start();
	iter_D.remove();
	cout << "\n\n\t\t sau khi khoi chay iterator_remove: " << endl;
	d.outputDlist();

	iter_D.add(t2);
	cout << "\n\n\t\t sau khi khoi chay iterator_add: " << endl;
	d.outputDlist();

	iter_D.add(t3);
	cout << "\n\n\t\t sau khi khoi chay iterator_add lan 2: " << endl;
	d.outputDlist();
	return 0;
}
