#include <iostream>
#include "Dlist/Dlist.h"
#include "Term/Term.h"
#include "Dlist/DlistIterator/DlistIterator.h"
#include "Poly/Poly.h"
using namespace std;

int main(int argc, char *argv[])
{
	CPoly p1;
	p1.inputPoly(3);
	p1.outputPoly();
	return 0;
}
