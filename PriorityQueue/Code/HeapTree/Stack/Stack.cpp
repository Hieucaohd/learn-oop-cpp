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
	if (isStackEmpty())
	/* Neu ngan xep rong.*/
	{
	    /* Thi khong lam gi ca.*/
	}
	else
	/* Neu ngan xep khong rong.*/
	{
		/* Thu hoi tung thanh phan.*/
		while (m_top->m_next != NULL)
		/* Duyet qua tat ca thanh phan trong ngan xep
		 * cho den khi ngan xep con lai 1 phan tu.
		 * */
		{
			CNopeStack *old_top = m_top;
			m_top = m_top->m_next;
			delete old_top;
		} // End while.

		delete m_top;
	}
}

CStack CStack::operator = (const CStack &S)
{
	
}

bool CStack::isStackEmpty()
{
	return m_top == NULL;
}

void CStack::push(const typeOfDataStack &data_parameter)
{
	/* Tao mot thanh phan moi de chua du lieu
	 * truyen vao.
	 * */
	CNopeStack *new_nope = new CNopeStack(data_parameter);
		
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

typeOfDataStack CStack::pop()
{
	if (!isStackEmpty())
	/* Neu ngan xep khong rong.*/
	{
		typeOfDataStack data_from_top = m_top->m_data;
	    CNopeStack *old_top = m_top;
		m_top = m_top->m_next;

		delete old_top; // Giai phong bo nho.
		return data_from_top;
	}
}

typeOfDataStack CStack::getTop()
{
	if (!isStackEmpty())
	/* Neu ngan xep khong rong.*/
	{
	    return m_top->m_data;
	}
}
