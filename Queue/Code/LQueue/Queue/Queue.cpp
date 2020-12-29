#include "Queue.h"

CQueue::CQueue()
{
	m_tail = NULL;
}

CQueue::CQueue(const CQueue &Q)
{
	
}

CQueue::~CQueue()
{
	/*comment*/
	if (isQueueEmpty())
	/* Neu hang doi rong.*/
	{
	    /* Thi khong lam gi ca.*/
	}
	else
	/* Neu hang doi khong rong.*/
	{
		while (m_tail->m_next != m_tail)
		/* Lap cho den khi hang doi con lai 1 phan tu.*/
		{
			/* Tao bien chay bien chay 
			 * chay tu phan tu head.*/
			CNope *run = m_tail->m_next; 
			m_tail->m_next = m_tail->m_next->m_next;
			delete run;
		} // End while.

		delete m_tail;
	}
}

CQueue CQueue::operator = (const CQueue &Q)
{
	
}

bool CQueue::isQueueEmpty()
{
	return (m_tail == NULL);
}

void CQueue::enQueue(const typeOfData & data_parameter)
{
	/* Tao mot phan tu moi.*/
	CNope *new_nope = new CNope(data_parameter);
	
	/* Them phan tu moi vao duoi hang doi.*/
	if (isQueueEmpty())
	/* Neu hang doi rong.*/
	{
	    m_tail = new_nope;
		m_tail->m_next = m_tail; // de tao danh sach lien ket vong tron.
	}
	else
	/* Neu hang doi khong rong.*/
	{
		new_nope->m_next = m_tail->m_next;
		m_tail->m_next = new_nope;
		m_tail = new_nope;
	}
}

typeOfData CQueue::deQueue()
{
	if (!isQueueEmpty())
	/* Neu hang doi khong rong.*/
	{
		/* Lay du lieu tu phan tu head.*/
		typeOfData data_of_head = m_tail->m_next->m_data;

		/* Xoa phan tu head va thu hoi bo nho.*/
		if (m_tail->m_next == m_tail)
		/* Neu hang doi chi co mot phan tu.*/
		{
			delete m_tail; // thu hoi bo nho.
			m_tail = NULL; // cho hang doi thanh rong.
		}
		else
		/* Neu hang doi co tu 2 phan tu tro len.*/
		{
			CNope *old_head = m_tail->m_next;
			/* Cho phan tu head tro den phan tu tiep theo.*/
			m_tail->m_next = m_tail->m_next->m_next; 
			delete old_head; // thu hoi bo nho.
		}

		return data_of_head;    
	}
	else
	/* Neu hang doi rong.*/
	{
		typeOfData null_return;
		return null_return;
	}
}

typeOfData CQueue::getHead()
{
	if (!isQueueEmpty())
	/* Neu hang doi khong rong.*/
	{
		return m_tail->m_next->m_data;
	}
	else
	/* Neu hang doi rong.*/
	{
		typeOfData null_return;
		return null_return;
	}
}
