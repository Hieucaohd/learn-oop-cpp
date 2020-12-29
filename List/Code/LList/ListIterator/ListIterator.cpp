#include "ListIterator.h"

CListIterator::CListIterator(CLinkedList &L)
{
	m_List_ptr = &L;
	m_current = m_List_ptr->m_head;
}

CListIterator::~CListIterator()
{
	
}

void CListIterator::start()
{
	m_current = m_List_ptr->m_head->m_next;
}

void CListIterator::advance()
{
	/* Dua vi tri hien thoi la vi tri tiep theo 
	 * trong danh sach.
	 * */
	m_current = m_current->m_next;
}

bool CListIterator::valid()
{
	return m_current != m_List_ptr->m_head;
}

typeOfData CListIterator::current()
{
	if (valid())
	/* Neu vi tri hien thoi co trong danh sach.*/
	{
	    return m_current->m_data;
	}
	else
	/* Neu vi tri hien thoi khong trong danh sach.*/
	{
		typeOfData null_return;
		return null_return;
	}
}

void CListIterator::add(const CNope &data_parameter)
{
	if (valid())
	/* Neu phan tu hien thoi nam trong danh sach.*/
	{
		/* Tao phan tu moi.*/
	    CNope *new_nope = new CNope(data_parameter);

		/* Them vao.*/
		m_current->m_precede->m_next = new_nope;
		new_nope->m_precede = m_current->m_precede;

		m_current->m_precede = new_nope;
		new_nope->m_next = m_current;

		m_List_ptr->m_length += 1;
	}
	else
	/* Neu vi tri hien thoi khong nam trong danh sach.*/
	{
		cout << "Vi tri hien thoi khong nam trong danh sach." << endl;
	}
}

void CListIterator::remove()
{
	if (valid())
	/* Neu vi tri hien thoi nam trong danh sach.*/
	{
		CNope *pre_ptr = m_current->m_precede;
		CNope *next_ptr = m_current->m_next;

		pre_ptr->m_next = next_ptr;
		next_ptr->m_precede = pre_ptr;
		
		CNope *delete_ptr = m_current;
		m_current = m_current->m_next;
		delete delete_ptr;

		m_List_ptr->m_length -= 1;
	}
	else
	/* Neu vi tri hien thoi khong nam trong danh sach.*/
	{
		cout << "Vi tri hien thoi khong nam trong danh sach." << endl;
	}
}
