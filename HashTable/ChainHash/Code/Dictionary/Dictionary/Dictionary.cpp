#include "Dictionary.h"

CDictionary::CDictionary()
{
	for (int i = 0; i < SIZE; i++)
	{
		m_array_datas[i] = NULL;
	}
}

CDictionary::CDictionary(const CDictionary &dic)
{
	
}

void CDictionary::operator = (const CDictionary &dic)
{
	
}

CDictionary::~CDictionary()
{
	
}

bool CDictionary::search(const typeOfKey & key, typeOfData & data)
{
	
}

void CDictionary::insert(const typeOfData & data_parameter, const typeOfKey & key_parameter, bool & is_success)
{
	
}

void CDictionary::deleteElementByKey(const typeOfKey & key)
{
	
}
