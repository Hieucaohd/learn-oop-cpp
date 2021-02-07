#include "NopeStack.h"

CNopeStack::CNopeStack(const typeOfDataStack &data_parameter)
{
	m_data = data_parameter;
	m_next = NULL;
}

CNopeStack::~CNopeStack()
{
	
}
