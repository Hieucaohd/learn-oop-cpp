#include "PriorityQueue.h"

CPriorityQueue::CPriorityQueue()
{
	m_size = 10;
	m_array_datas = new CNope[m_size];
	m_last = - 1;
}

CPriorityQueue::CPriorityQueue(int size_parameter)
{
	m_size = size_parameter; // khoi tao kich thuoc cua mang array_datas;
	m_last = -1; // khoi tao so luong phan tu trong hang uu tien = 0;
	m_array_datas = new CNope[m_size]; // cap phat dong cho mang array_datas;
}

CPriorityQueue::CPriorityQueue(CNope *array_datas_parameter, int number_of_elements)
{
	/* Khoi tao kich co cua mang array_datas co kich co gap doi mang chuyen vao.*/
	m_size = number_of_elements * 2 + 1;
	m_array_datas = new CNope[m_size];

	/* Khoi tao so luong phan tu trong hang uu tien.*/
	m_last = number_of_elements - 1;

	/* Sao chep cac phan tu tu mang truyen vao sang mang array_datas.*/
	for (int i = 0; i < m_last; i++)
	{
		m_array_datas[i] = array_datas_parameter[i];
	}

	/* Ta se xet cac phan tu tu vi tri (phan nguyen cua)(n/2 - 1) (voi n la so 
	 * luong phan tu trong hang uu tien) den vi tri 0.*/
	int from_vertex = (int)(number_of_elements/2.0 - 1);

	for (int i = from_vertex; i >= 0; i--)
	{
		/* Duyet cac phan tu i = from_vertex, ... , 2, 1, 0.
		 * Dua chung xuong vi tri thich hop.
		 * Ta se thu duoc cay thu tu bo phan hoan chinh.
		 * */
		shiftDown(i);
	}
}

CPriorityQueue::CPriorityQueue(const CPriorityQueue &priority_queue)
{
	/* Cap phat bo nho.*/
	m_size = priority_queue.m_size;
	m_array_datas = new CNope[m_size];

	/* Sao chep cac phan tu.*/
	m_last = priority_queue.m_last;

	for (int i = 0; i <= m_last; i++)
	{
		m_array_datas[i] = priority_queue.m_array_datas[i];
	}
}

CPriorityQueue::CPriorityQueue(const CPriorityQueue *priority_queue_ptr)
{
	/* Cap phat bo nho.*/
	m_size = priority_queue_ptr->m_size;
	m_array_datas = new CNope[m_size];

	/* Sao chep cac phan tu.*/
	m_last = priority_queue_ptr->m_last;

	for (int i = 0; i <= m_last; i++)
	{
		m_array_datas[i] = priority_queue_ptr->m_array_datas[i];
	}
}

CPriorityQueue CPriorityQueue::operator = (const CPriorityQueue &priority_queue)
{
	if (m_last >= 0)
	/* Neu hang uu tien cu khong rong.*/
	{
	    /* Thi ta phai giai phong bo nho.*/
		delete [] m_array_datas;
	}

	/* Cap phat bo nho moi.*/
	m_size = priority_queue.m_size;
	m_array_datas = new CNope[m_size];

	/* Sao chep cac phan tu.*/
	m_last = priority_queue.m_last;

	for (int i = 0; i <= m_last; i++)
	{
		m_array_datas[i] = priority_queue.m_array_datas[i];
	}

	return *this;
}

CPriorityQueue::~CPriorityQueue()
{
	delete [] m_array_datas;
}

CNope CPriorityQueue::findMin()
{
	return m_array_datas[0];
}

CNope CPriorityQueue::deleteMin()
{
	/* Lay du lieu.*/
	CNope take_nope;
	take_nope = m_array_datas[0];

	/* Thay the phan tu o goc bang phan tu o muc thap nhat va o ngoai cung ben phai.*/
	m_array_datas[0] = m_array_datas[m_last]; 

	/* Giam do dai cua mang va thu hoi bo nho.*/
	m_last -= 1;

	/* Sau do dua phan tu o goc xuong vi tri thich hop.*/
	shiftDown(0);

	return take_nope;
}

int findParent(const int &child_index)
{
	/* Ham dung de tim chi so cha cua 
	 * chi so child_index.
	 * */

	int parent_index; // bien luu lai chi so cua cha.

	if (child_index % 2 != 0)
	/* Neu no la con trai, vi con trai co dang la: 2i + 1 nen no la so le.*/
	{
	    parent_index = (child_index - 1) / 2;
	}
	else if (child_index % 2 == 0)
	/* Neu no la con phai, vi con phai co dang la: 2i + 2 nen no la so chan.*/
	{
		parent_index = child_index / 2 - 1;
	}

	return parent_index;
}

void CPriorityQueue::upSizeArray()
{
	if (m_last == m_size - 1)
	/* Neu mang da day.*/
	{
	    /* Thi ta tao ra mot mang moi co kich
		 * thuoc gap doi mang cu.*/
		CNope *new_array_datas = new CNope[m_size * 2 + 1];

		/* Sau do sao chep mang cu sang mang moi.*/
		for (int i = 0; i <= m_last; i++)
		{
			new_array_datas[i] = m_array_datas[i];
		}

		/* Xoa va thu hoi bo nho cua mang cu.*/
		delete [] m_array_datas;

		/* Sao chep tu mang moi.*/
		m_size = m_size * 2 + 1;
		m_array_datas = new_array_datas;
	}
}

void CPriorityQueue::insert(const typeOfData &data_parameter, const typeOfPriority &priority_parameter)
{
	/* Trong truong hop mang da day thi ta
	 * tang kich thuoc cua mang len.*/
	upSizeArray();

	/* Tao phan tu moi can them vao.*/
	CNope new_nope(data_parameter, priority_parameter);

	/* Tang do dai cua mang them 1 doi vi, de chua phan tu moi.*/
	m_last += 1;

	/* Dau tien, them phan tu moi vao muc thap nhat, ngoai cung ben phai.*/
	m_array_datas[m_last] = new_nope;

	/* Sau do, dua phan tu moi len vi tri thich hop.*/
	int child = m_last; // bien child luu lai chi so cua con.
	int parent = findParent(child); // bien parent luu lai chi so cua cha.

	while (child > 0)
	/* Neu con van co cha.*/
	{
		if (m_array_datas[child].m_priority < m_array_datas[parent].m_priority)
		/* Kiem tra xem gia tri uu tien cua con co nho hon cua cha khong.*/
		{
			/* Neu nho hon thi hoan doi cha voi con.*/
			m_array_datas[child] = m_array_datas[parent];
			m_array_datas[parent] = new_nope;

			/* Sau do, dua con len vi tri cua cha de duyet tiep.*/
			child = parent;
			parent = findParent(child);
		}
		else
		/* Neu gia tri uu tien cua con lon hon cua cha.*/
		{
			/* Thi ket thuc vong lap.*/
			break;
		}
	} // End while.
}

void CPriorityQueue::insert(const CNope &new_nope)
{
	/* Trong truong hop mang da day thi ta
	 * tang kich thuoc cua mang len.*/
	upSizeArray();

	/* Tang do dai cua mang them 1 doi vi, de chua phan tu moi.*/
	m_last += 1;

	/* Dau tien, them phan tu moi vao muc thap nhat, ngoai cung ben phai.*/
	m_array_datas[m_last] = new_nope;

	/* Sau do, dua phan tu moi len vi tri thich hop.*/
	int child = m_last; // bien child luu lai chi so cua con.
	int parent = findParent(child); // bien parent luu lai chi so cua cha.

	while (child > 0)
	/* Neu con van co cha.*/
	{
		if (m_array_datas[child].m_priority < m_array_datas[parent].m_priority)
		/* Kiem tra xem gia tri uu tien cua con co nho hon cua cha khong.*/
		{
			/* Neu nho hon thi hoan doi cha voi con.*/
			m_array_datas[child] = m_array_datas[parent];
			m_array_datas[parent] = new_nope;

			/* Sau do, dua con len vi tri cua cha de duyet tiep.*/
			child = parent;
			parent = findParent(child);
		}
		else
		/* Neu gia tri uu tien cua con lon hon cua cha.*/
		{
			/* Thi ket thuc vong lap.*/
			break;
		}
	} // End while.
}

void CPriorityQueue::shiftDown(int index)
{
	CNope take_nope;
	take_nope = m_array_datas[index]; // bien take_nope luu du lieu o dinh index.
	int parent = index; // bien parent luu lai chi so cua dinh cha.
	int child = 2 * parent + 1; // bien child luu lai chi so cua dinh con trai.

	while (child <= m_last)
	/* Khi ma phan tu dang xet van dang o trong cay.*/
	{
		int right = child + 1; // bien right luu lai chi so cua dinh con phai.

		if (right <= m_last)
		/* Kiem tra xem chi so cua dinh con phai co ton tai hay khong.*/
		{
		    if (m_array_datas[right].m_priority < m_array_datas[child].m_priority)
		    /* Neu dinh con phai co gia tri uu tien nho hon dinh con trai.*/
		    {
				/* Thi ta xet dinh con phai.*/
		        child = right;
		    }
		}

		if (take_nope.m_priority > m_array_datas[child].m_priority)
		/* Neu gia tri uu tien cua take_nope lon hon dinh con.*/
		{
			/* Hoan doi du lieu o dinh cha voi dinh con.*/
			m_array_datas[parent] = m_array_datas[child]; 		   
			m_array_datas[child] = take_nope;

			/* Di xuong nhanh cay con de xet tiep.*/
			parent = child;
			child = 2 * parent + 1;
		}
		else
		/* Neu nho hon.*/
		{
			/* Thi thoat vong lap va ket thuc.*/
			break;
		}

	} // end while.
}

int CPriorityQueue::lengthOfPriQueue()
{
	return m_last + 1;
}
