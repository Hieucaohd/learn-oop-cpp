#include "Nope.h"

CNope::CNope(typeOfData & data_parameter)
{
	m_data = data_parameter;
	m_first_child = NULL;
	m_next_sibling = NULL;
}

CNope::~CNope()
{
	
}


