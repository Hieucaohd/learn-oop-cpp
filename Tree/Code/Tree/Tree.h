#pragma once
#include <iostream>
#include <string>
#include "../Nope/Nope.h"
using namespace std;

class CTree
{
private:
public:
	CNope *m_root;
	CTree(typeOfData & data_of_root);
	/* Constructor: khoi tao cay co mot goc.
	 * */

	~CTree();
	/* Destructor.
	 * */
};
