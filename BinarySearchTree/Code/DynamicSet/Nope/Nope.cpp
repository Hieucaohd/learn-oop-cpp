#include "Nope.h"

CNope::CNope(const typeOfData & data_parameter, const typeOfKey & key_parameter)
{
	m_key = key_parameter;
	m_data = data_parameter;
	m_left = NULL;
	m_right = NULL;
}

CNope::~CNope()
{
	
}
