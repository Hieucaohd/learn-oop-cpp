#include <iostream>
#include "Dlist/Dlist.h"
#include "Term/Term.h"
#include "Dlist/DlistIterator/DlistIterator.h"
#include "Poly/Poly.h"
using namespace std;

int main(int argc, char *argv[])
{
	system("clear");
	CPoly p1, p2;
	p1.inputPoly(3);
	p1.outputPoly();

	p2.inputPoly(4);
	p2.outputPoly();

	CPoly p3 = p1 + p2;
	p3.outputPoly();
	return 0;
}
