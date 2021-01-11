#include "Nope.h"

CNope::CNope()
{
	
}

CNope::CNope(const typeOfData &data_parameter, const typeOfPriority &priority_parameter)
{
	m_data = data_parameter;
	m_priority = priority_parameter;
}

CNope::~CNope()
{
	
}

void CNope::operator = (const CNope &nope_parameter)
{
	m_data = nope_parameter.m_data;
	m_priority = nope_parameter.m_priority;
}
