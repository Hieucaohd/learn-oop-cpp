#include "Nope.h"

CNope::CNope(const typeOfData &data_parameter)
{
	m_data = data_parameter;
	m_next = NULL;
	m_precede = NULL;
}

CNope::~CNope()
{
	
}
