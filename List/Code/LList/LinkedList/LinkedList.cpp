#include "LinkedList.h"

CLinkedList::CLinkedList()
{
	m_head = new CNope(0); // 0 la con so bat ki.
	m_head->m_next = m_head;
	m_head->m_precede = m_head;
	
	/* Do dai danh sach ban dau bang 0.*/
	m_length = 0;
}

CLinkedList::CLinkedList(const CLinkedList &L)
{
	if (L.m_length == 0)
	/* Neu L la danh sach rong.*/
	{
	    m_head = new CNope(L.m_head->m_data);
		m_head->m_next = m_head;
		m_head->m_precede = m_head;

		m_length = 0;
	}
	else
	/* Neu L khong rong.*/
	{
		/* Tao con tro head.*/
		m_head = new CNope(L.m_head->m_data);
		m_head->m_next = m_head;
		m_head->m_precede = m_head;
		m_length = 0;
		

		/* Tao con tro CHAY.*/
		CNope *cur = L.m_head->m_next; 

		int count = 1; // bien chay.
		while (count <= L.m_length) 
		/* Chay het danh sach L.*/
		{
			appendElement(cur->m_data);
			cur = cur->m_next;
			count += 1;
		} // End while.
	}
}

CLinkedList::~CLinkedList()
{
	/* Tao bien con tro CHAY.*/
	CNope *cur = m_head->m_next;

	int count = 1;
	while (count <= length())
	/* Chay den het danh sach.*/
	{
		CNope *delete_ptr = cur;
		cur = cur->m_next;
		count += 1;
		delete delete_ptr;
	} // End while.
}

CLinkedList CLinkedList::operator = (const CLinkedList &L)
{
	if (!isListEmpty())
	/* Neu danh sach hien tai khong rong, 
	 * thi ta xoa va thu hoi bo nho va copy
	 * tung phan tu cua L sang danh sach. */
	{
		/* Xoa danh sach cu.*/
		/* Tao bien con tro CHAY.*/
		CNope *cur = m_head->m_next;

		int count = 1;
		while (count <= length())
		/* Chay den het danh sach.*/
		{
			CNope *delete_ptr = cur;
			cur = cur->m_next;
			count += 1;
			delete delete_ptr;
		} // End while.
		/* Xoa xong.*/
	}

	/* Copy tu danh sach L.*/
	if (L.m_length == 0)
	/* Neu L la danh sach rong.*/
	{
	    m_head = new CNope(L.m_head->m_data);
		m_head->m_next = m_head;
		m_head->m_precede = m_head;

		m_length = 0;
	}
	else
	/* Neu L khong rong.*/
	{
		/* Tao con tro head.*/
		m_head = new CNope(L.m_head->m_data);
		m_head->m_next = m_head;
		m_head->m_precede = m_head;
		m_length = 0;
		

		/* Tao con tro CHAY.*/
		CNope *cur = L.m_head->m_next; 

		int count = 1; // bien chay.
		while (count <= L.m_length) 
		/* Chay het danh sach L.*/
		{
			appendElement(cur->m_data);
			cur = cur->m_next;
			count += 1;
		} // End while.
	}
	
	return *this;
}

bool CLinkedList::isListEmpty()
{
	return (m_length == 0);
}

int CLinkedList::length()
{
	return m_length;
}

void CLinkedList::insertElement(const typeOfData &data_parameter, int position)
{
	if (1 <= position && position <= m_length)
	/* Neu vi tri can chen nam trong danh sach.*/
	{
	    CNope *new_nope = new CNope(data_parameter);
		CNope *cur = m_head; // tao con tro CHAY.

		int i = 1;
		while (i <= position)
		/* Dua con tro CHAY chay den vi tri can chen.*/
		{
			cur = cur->m_next;
			i += 1;
		} // End while.
		
		/* Chen vao vi tri position.*/
		/* Noi o phia truoc.*/
		cur->m_precede->m_next = new_nope;
		new_nope->m_precede = cur->m_precede;
		/* Noi o phia sau.*/
		new_nope->m_next = cur;
		cur->m_precede = new_nope;

		/* Tang do dai them 1 doi vi.*/
		m_length += 1;
	}
	else
	/* Neu vi tri can chen khong nam trong danh sach.*/
	{
		cout << "Vi tri can chen khong nam trong danh sach." << endl;
	}
}


void CLinkedList::appendElement(const typeOfData &data_parameter)
{
	/* Tao mot thanh phan moi.*/
	CNope *new_nope = new CNope(data_parameter);
	
	/* Moc noi con tro duoi va new_nope.*/
	m_head->m_precede->m_next = new_nope;
	new_nope->m_precede = m_head->m_precede;
	
	/* Moc noi new_nope vao duoi danh sach.*/
	m_head->m_precede = new_nope;
	new_nope->m_next = m_head;

	/* Tang do dai cua danh sach them 1 don vi.*/
	m_length += 1; 
}

void CLinkedList::deleteElement(int position)
{
	if (1 <= position && position <= m_length)
	/* Neu vi tri can xoa nam trong danh sach.*/
	{
		/* Khoi tao con tro CHAY.*/
		CNope *cur = m_head;
		
		int count = 1;
		while (count <= position)
		/* Cho con tro CHAY chay den vi tri can xoa.*/
		{
			cur =cur->m_next;
			count += 1;
		} // End while.

		/* Xoa*/
		cur->m_precede->m_next = cur->m_next;
		cur->m_next->m_precede = cur->m_precede;

		delete cur; // giai phong bo nho.
		m_length -= 1; // giam do dai cua danh di 1 don vi.
	}
	else
	/* Neu vi tri can xoa khong nam trong danh sach.*/
	{
		cout << "Vi tri can xoa khong nam trong danh sach." << endl;
	}
}

typeOfData CLinkedList::findElement(int position)
{
	if (1 <= position && position <= m_length)
	/* Neu vi tri can xoa nam trong danh sach.*/
	{
		/* Khoi tao con tro CHAY.*/
		CNope *cur = m_head;
		
		int count = 1;
		while (count <= position)
		/* Cho con tro CHAY chay den vi tri can tim.*/
		{
			cur =cur->m_next;
			count += 1;
		} // End while.

		return cur->m_data;
	}
}
