#include "Dlist.h"

CDlist::CDlist()
{
	m_elements = NULL;
	m_size = 0;
	m_last = -1;
}

CDlist::CDlist(int size_parameter)
{
	if (size_parameter > 0)
	// Neu kich co cua mang nguyen duong.
   	{
		m_elements = new typeOfElement[size_parameter];
		m_size = size_parameter;
		m_last = -1;
	}
	else
	// Neu kich co cua mang nguyen am hoac bang 0.
	{
		cout << "Hay khoi tao mot mang co so phan tu nguyen duong." << endl;
	}
}

CDlist::CDlist(const CDlist &L)
{
	m_elements = new typeOfElement[L.m_size];
	m_size = L.m_size;
	m_last = L.m_last;
	for (int i = 0; i <= m_last; i++)
	{
		m_elements[i] = L.m_elements[i];
	}
}

CDlist & CDlist::operator = (const CDlist &L)
{
	/*Neu m_size != L.m_size thi ta cap phat mot mang moi 
	 *co kich thuoc bang L.m_size.
	 * */
	if (m_size != L.m_size)
   	{
		delete [] m_elements;
		m_elements = new typeOfElement[L.m_size];
		m_size = L.m_size;
	}
	m_last = L.m_last;
	for (int i = 0; i < m_last; i++)
	{
		m_elements[i] = L.m_elements[i];	
	}
	return *this;
}

CDlist::~CDlist()
{
	delete [] m_elements;
}

void CDlist::inputDlist(int numberElements)
{
	if (numberElements > m_size)
	// Neu so phan tu can nhap lon hon kich thuoc cua mang.
   	{
		delete [] m_elements;
		while(numberElements >=  m_size)
		{
			m_size = m_size + 1;
		}
		m_elements = new typeOfElement[m_size];
		m_last = numberElements - 1;
		for (int i = 0; i <= m_last; i++)
		{
			cout << "Nhap phan tu thu " << i + 1 << ": " << endl;
			cin >> m_elements[i];	
		}
	}
	else
	// Neu so phan tu can nhap nho hon kich thuoc cua mang.
	{
		m_last = numberElements - 1;
		for (int i = 0; i <= m_last; i++)
		{
			cout << "Nhap phan tu thu " << i + 1 << ": " << endl;
			cin >> m_elements[i];
		}
	}
}

void CDlist::outputDlist()
{
	if(!isDlistEmpty())
	// Neu mang khong rong.
	{	 	   
		for (int i = 0; i <= m_last; i++)
		{
			cout << m_elements[i] << endl;
		}
	}
	else
	// Neu mang rong.
	{
		cout << "Khong co phan tu nao!" << endl;
	}
	cout << endl;
}

void CDlist::insert(const typeOfElement &element_parameter, int position_insert)
{
	if (1 <= position_insert && position_insert <= length())
	// Kiem tra xem vi tri chen co nam trong danh sach hay khong.
	{
	    if (length() < m_size)
	    // Neu so phan tu hien co trong danh sach nho hon kich co cua danh sach.
	    {
			for (int i = m_last + 1; i > position_insert - 1; i--)
			{
				m_elements[i] = m_elements[i - 1];
			}

			// Chen phan tu vao vi tri insert.
			m_elements[position_insert - 1] = element_parameter;
			m_last += 1;
	    }
		else
		// Neu so phan tu hien co lon hon hoac bang kich co cua danh sach. 
		{
			// Ta tao mot mang moi co kich thuoc x2 mang ban dau.
			typeOfElement *newArray = new typeOfElement[m_size * 2 + 1];

			// Sao chep cac phan tu tu vi tri 0 -> position_insert - 2 tu m_elements sang newArray.
			for (int i = 0; i < position_insert - 1; i++)
			{
				newArray[i] = m_elements[i];
			}

			// Sao chep cac phan tu tu position_insert -> m_last tu m_elements sang newArray.
			for (int i = m_last + 1; i > position_insert - 1; i--)
			{
				newArray[i] = m_elements[i - 1];
			}

			// Chen phan tu vao vi tri insert.
			newArray[position_insert - 1] = element_parameter;
			
			// Sao chep mang newArray sang mang m_elements.
			delete [] m_elements;
			m_elements = newArray;
			m_size = m_size * 2 + 1;
			m_last += 1;
		}
	}
	else
	// Neu vi tri can insert khong nam trong danh sach.
	{
		cout << "Vi tri can insert khong nam trong danh sach." << endl;
	}
}

void CDlist::append(const typeOfElement &element_parameter)
{
	if (length() < m_size)
	// Neu so phan tu hien co trong danh sach nho hon kich thuoc cua danh sach.
	{
	    m_last++;
		m_elements[m_last] = element_parameter;
	}
	else
	// Neu so phan tu hien co trong danh sach lon hon hoac bang kich thuoc cua danh sach.
	{
		// Ta cap phat mot mang moi co kich thuoc gap doi mang cu.
		typeOfElement *newArray = new typeOfElement[m_size * 2 + 1];

		// Sao chep cac phan tu tu m_elements sang newArray.
		for (int i = 0; i <= m_last; i++)
		{
			newArray[i] = m_elements[i];
		}

		// Them phan tu vao cuoi mang newArray
		newArray[m_last + 1] = element_parameter;

		// Xoa mang m_elements cu va sao chep sang mang newArray.
		delete [] m_elements;
		m_elements = newArray;
		m_size = m_size * 2 + 1;
		m_last ++;
	}
}

void CDlist::deleteElement(int position)
{
	if (1 <= position && position <= length())
	// Neu vi tri can xoa nam trong danh sach.
	{
		for (int i = position - 1; i <= m_last - 1; i++)
		{
			m_elements[i] = m_elements[i + 1];
		}
		m_last--;
	}
	else
	// Neu vi tri can xoa khong nam trong danh sach.
	{
		cout << "Vi tri can xoa khong nam trong danh sach" << endl;
	}
}

typeOfElement CDlist::findElement(int position)
{
	if (1 <= position && position <= length())
	// Neu vi tri can tim nam trong danh sach.
	{
	    return m_elements[position - 1];
	}
	else
	// Neu vi tri can tim khong nam trong danh sach.
	{
		cout << "Vi tri can tim khong nam trong danh sach." << endl;
	}
}


	
