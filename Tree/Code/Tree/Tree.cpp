#include "Tree.h"

CTree::CTree(typeOfData & data_of_root)
{
	m_root = new CNope(data_of_root);
}

CTree::~CTree()
{
	
}
