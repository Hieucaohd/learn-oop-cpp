#include "DlistIterator.h"

CDlistIterator::CDlistIterator(CDlist &L)
{
	m_Dlist_ptr = &L;
	m_current = -1;
}

CDlistIterator::~CDlistIterator()
{

}

void CDlistIterator::start()
{
	m_current = 0;
}

bool CDlistIterator::valid()
{
	return (0 <= m_current && m_current <= m_Dlist_ptr->m_last);
}

void CDlistIterator::advance()
{
	if (valid())
	/* Phan tu hien thoi co mat trong danh sach.*/
	{
	    m_current++;
	}
	else
	/* Phan tu hien thoi khong co mat trong danh sach.*/
	{
		cout << "Phan tu hien thoi khong co mat trong danh sach." << endl;
	}
}

typeOfElement & CDlistIterator::current()
{
	if (valid())
	/* Phan tu hien thoi co mat trong danh sach.*/
	{
	 	return m_Dlist_ptr->m_elements[m_current];
	}
	else
	/* Phan tu hien thoi khong co mat trong danh sach.*/
	{
		cout << "Phan tu hien thoi khong co trong danh sach." << endl;
	}
}

void CDlistIterator::add(const typeOfElement &element_parameter)
{
	if (valid())
	/* Neu phan tu hien thoi co trong danh sach.*/
	{
	 	m_Dlist_ptr->insert(element_parameter, m_current + 1);   
		m_current ++;
	}
	else
	/* Neu phan tu hien thoi khong co trong danh sach.*/
	{
		cout << "Phan tu hien thoi khong co trong danh sach." << endl;
	}
}

void CDlistIterator::remove()
{
	if (valid())
	/* Neu phan tu hien thoi co trong danh sach.*/
	{
	    m_Dlist_ptr->deleteElement(m_current + 1);
	}
	else
	/* Neu phan tu hien thoi khong co trong danh sach.*/
	{
		cout << "Phan tu hien thoi khong co trong danh sach." << endl;
	}
}
