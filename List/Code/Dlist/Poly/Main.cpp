#include <iostream>
#include "Dlist/Dlist.h"
#include "Term/Term.h"
using namespace std;

int main(int argc, char *argv[])
{
	system("clear");
	CTerm t1(4,4);
	CDlist d(3);

	d.inputDlist(3);
	cout << "\n\n\t\t truoc khi lam gi do: " << endl;
	d.outputDlist();
	
	d.insert(t1, 2);
	cout << "\n\n\t\t sau khi insert: " << endl;
	d.outputDlist();

	d.append(t1);
	cout << "\n\n\t\t sau khi append: " << endl;
	d.outputDlist();
	return 0;
}
