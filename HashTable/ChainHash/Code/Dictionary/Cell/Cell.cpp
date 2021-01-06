#include "Cell.h"

CCell::CCell()
{
	m_next = NULL;
}

CCell::CCell(const typeOfData & data_parameter, const typeOfKey & key_parameter)
{
	m_data = data_parameter;
	m_key = key_parameter;
	m_next = NULL;
}

CCell::~CCell()
{
	
}
