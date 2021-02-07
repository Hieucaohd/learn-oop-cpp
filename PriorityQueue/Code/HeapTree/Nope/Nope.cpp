#include "Nope.h"

CNope::CNope()
{
	typeOfData data_default = ' ';
	typeOfPriority priority_default = 403;

	m_data = data_default;
	m_priority = priority_default;
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

void copyTree(CNope * from_nope, CNope * &to_nope)
{
	if (from_nope == NULL)
	{
	 	to_nope = NULL;   
	}
	else
	{
		to_nope = new CNope(from_nope->m_data, from_nope->m_priority);
		copyTree(from_nope->m_left, to_nope->m_left);
		copyTree(from_nope->m_right, to_nope->m_right);
	}
}

CNope CNope::operator = (const CNope &nope_parameter)
{
	m_data = nope_parameter.m_data;
	m_priority = nope_parameter.m_priority;
	
	copyTree(nope_parameter.m_left, m_left);
	copyTree(nope_parameter.m_right, m_right);

	return *this;
}

ostream &operator << (ostream &output, CNope nope_parameter)
{
	output << nope_parameter.m_data << "(" << nope_parameter.m_priority << ")";
	return output;
}

ostream &operator << (ostream &output, CNope *nope_parameter)
{
	output << nope_parameter->m_data << "(" << nope_parameter->m_priority << ")";
	return output;
}
