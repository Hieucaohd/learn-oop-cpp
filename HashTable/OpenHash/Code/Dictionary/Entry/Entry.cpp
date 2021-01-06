#include "Entry.h"

CEntry::CEntry()
{
	
}

CEntry::CEntry(typeOfData & data_parameter,typeOfKey & key_parameter, stateType & state_parameter)
{
	m_data = data_parameter;
	m_key = key_parameter;
	m_state = state_parameter;
}

CEntry::~CEntry()
{
	
}
