#include "Nope.h"

CNope::CNope()
{
	m_left = NULL;
	m_right = NULL;
}

CNope::CNope(const typeOfData &data_parameter, const typeOfPriority &priority_parameter)
{
	m_data = data_parameter;
	m_priority = priority_parameter;
	m_left = NULL;
	m_right = NULL;
}

CNope::~CNope()
{
	
}

void CNope::operator = (const CNope &nope_parameter)
{
	m_data = nope_parameter.m_data;
	m_priority = nope_parameter.m_priority;
	m_left = nope_parameter.m_left;
	m_right = nope_parameter.m_right;
}
