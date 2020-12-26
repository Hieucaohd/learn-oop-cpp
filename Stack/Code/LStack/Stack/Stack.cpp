#include "Stack.h"

CStack::CStack()
{
	m_top = NULL;
}

CStack::CStack(const CStack &S)
{
	
}

CStack::~CStack()
{
	/* Thu hoi tung thanh phan.*/
	while (m_top != NULL)
	/* Duyet qua tat ca thanh phan trong ngan xep
	 * cho den khi top == NULL.
	 * */
	{
		CNope *old_top = m_top;
		m_top = m_top->m_next;
		delete old_top;
	} // End while.
}

CStack CStack::operator = (const CStack &S)
{
	
}

bool CStack::isStackEmpty()
{
	return m_top == NULL;
}

void CStack::push(const typeOfData &data_parameter)
{
	/* Tao mot thanh phan moi de chua du lieu
	 * truyen vao.
	 * */
	CNope *new_nope = new CNope(data_parameter);
		
	if (isStackEmpty())
	/* Neu ngan xep ban dau rong.*/
	{
		m_top = new_nope;
	}
	else
	/* Neu ngan xep ban dau khong rong.*/
	{
		/* Thi ta chen phan tu moi vao dau ngan xep.*/
		new_nope->m_next = m_top;
		m_top = new_nope;
	}
}

typeOfData CStack::pop()
{
	if (!isStackEmpty())
	/* Neu ngan xep khong rong.*/
	{
		typeOfData data_from_top = m_top->m_data;
	    CNope *old_top = m_top;
		m_top = m_top->m_next;

		delete old_top; // Giai phong bo nho.
		return data_from_top;
	}
}

typeOfData CStack::getTop()
{
	if (!isStackEmpty())
	/* Neu ngan xep khong rong.*/
	{
	    return m_top->m_data;
	}
}
