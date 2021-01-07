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
	/* Ta phai thu hoi toan bo day chuyen trong tu dien.*/
	for (int i = 0; i < SIZE; i++)
	{
		if (m_array_datas[i] != NULL)
		/* Neu day chuyen khong rong.*/
		{
			while (m_array_datas[i]->m_next != NULL)
			/* Lap cho den khi con 1 phan tu trong day chuyen.*/
			{
				CCell *old_ptr = m_array_datas[i];
				m_array_datas[i] = m_array_datas[i]->m_next;
				delete old_ptr;
			} // End while.

			/* Xoa phan tu cuoi cung trong day chuyen.*/
			delete m_array_datas[i];
			m_array_datas[i] = NULL;
		}
	}
	
}

void CDictionary::hieu()
{
}

bool CDictionary::search(const typeOfKey & key, typeOfData & take_data)
{
	/* Tao bien chay.*/
	CCell *current_ptr = m_array_datas[hash(key)];

	while (current_ptr != NULL)
	/*comment*/
	{
		if (current_ptr->m_key == key)
		/* Neu tim thay phan tu can tim.*/
		{
		    take_data = current_ptr->m_data;
			return true;
		}

		/* Neu khong thi cho chay tiep.*/
		current_ptr = current_ptr->m_next;
	} // End while.

	return false;
}

void CDictionary::insert(const typeOfData & data_parameter, const typeOfKey & key_parameter, bool & is_success)
{
	/* Tao bien de lay du lieu tu ham search.*/
	typeOfData take_data;

	if (!search(key_parameter, take_data))
	/* Neu khoa chua co trong tu dien.*/
	{
		/* Tao phan tu moi.*/
		CCell *new_cell = new CCell(data_parameter, key_parameter);

		/* Them phan tu moi vao dau day chuyen.*/
		new_cell->m_next = m_array_datas[hash(key_parameter)];
		m_array_datas[hash(key_parameter)] = new_cell;

		is_success = true;
	}
	else
	/* Neu khoa da ton tai trong tu dien.*/
	{
		cout << "Khoa da co trong tu dien." << endl;
		is_success = false;
	}
}

void CDictionary::deleteElementByKey(const typeOfKey & key)
{
	/* Tao 2 con tro chay.*/
	CCell *precede_ptr = NULL; // con tro sau.
	CCell *current_ptr = m_array_datas[hash(key)]; // con tro truoc.

	/* Tao con tro the.*/
	CCell *old_ptr;

	while (current_ptr != NULL)
	/* Chay cho den het day chuyen.*/
	{
		if (current_ptr->m_key == key)
		/* Neu gap phan tu can xoa.*/
		{
		    if (current_ptr == m_array_datas[hash(key)])
		    /* Neu phan tu can xoa nam o dau day truyen.*/
		    {
				old_ptr = m_array_datas[hash(key)];
		        m_array_datas[hash(key)] = m_array_datas[hash(key)]->m_next;
				delete old_ptr;
		    }
			else
			/* Neu phan tu can xoa khong nam o dau day chuyen.*/
			{
				precede_ptr->m_next = current_ptr->m_next;
				delete current_ptr;
			}

			break; // ket thuc vong lap.
		}
		else
		/* Neu khong gap phan tu can xoa.*/
		{
			/* Thi ta di tiep.*/
			precede_ptr = current_ptr;
			current_ptr = current_ptr->m_next;
		}

	} // End while.
}

int CDictionary::hash(const typeOfKey & key)
{
	return (key % SIZE);
}
