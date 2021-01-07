#include "Dictionary.h"

CDictionary::CDictionary()
{
	m_array_datas = new CEntry[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		m_array_datas[i].m_state = EMPTY;
	}
}

CDictionary::~CDictionary()
{
	delete [] m_array_datas;
}

bool CDictionary::search(typeOfKey & key, typeOfData & take_data)
{
	int index_ACTIVE, index_EMPTY_DELETED;
	if (find(key, index_ACTIVE, index_EMPTY_DELETED))
	/* Neu tim thay.*/
	{
	    /* Thi lay du lieu ra va ket thuc.*/
		take_data = m_array_datas[index_ACTIVE].m_data;
		return true;
	}
	else
	/* Neu khong tim thay.*/
	{
		/* Thi tra ve false.*/
		return false;
	}
}

void CDictionary::insert(const typeOfData &data_parameter, const typeOfKey &key_parameter, bool &is_success)
{
	int index_ACTIVE, index_EMPTY_DELETED;
	
	if ( !find(key_parameter, index_ACTIVE, index_EMPTY_DELETED))
	{
		if (m_array_datas[index_EMPTY_DELETED].m_state == DELETED || m_array_datas[index_EMPTY_DELETED].m_state == EMPTY)
		/* Neu khoa chua ton tai trong mang.*/
		{
			m_array_datas[index_EMPTY_DELETED].m_state = ACTIVE;
			m_array_datas[index_EMPTY_DELETED].m_key = key_parameter;
			m_array_datas[index_EMPTY_DELETED].m_data = data_parameter;

			is_success = true;
		}
	}
	else
	/* Neu khoa da ton tai trong mang.*/
	{
		is_success = false;
	}
}

void CDictionary::deleteElementByKey(typeOfKey & key)
{
	int index_ACTIVE, index_EMPTY_DELETED;

	if (find(key, index_ACTIVE, index_EMPTY_DELETED))
	/* Neu tim thay phan tu can xoa.*/
	{
	    m_array_datas[index_ACTIVE].m_state = DELETED;
	}
}

bool CDictionary::find(const typeOfKey & key, int & index_ACTIVE, int & index_EMPTY_DELETED)
{
	int position = hash(key);
	index_EMPTY_DELETED = position; // dat o dau day tham do.

	for (int number = 0; number < SIZE; number++)
	{
		/* Vi tri tham do lan thu number.
		 * Khi number = 0 thi n = position.*/
		int n = probing(position, number); 

		if (m_array_datas[n].m_state == ACTIVE && m_array_datas[n].m_key == key)
		/* Neu tim thay phan tu co khoa can tim.*/
		{
			/* Thi ta danh dau vi tri do va ket thuc.*/
			index_ACTIVE = n;
			return true; 
		}
		else if (m_array_datas[n].m_state == EMPTY && m_array_datas[index_EMPTY_DELETED].m_state != DELETED)
		/* Neu gap vi tri EMPTY va truoc do khong gap vi tri DELETED.*/
		{
			/* Thi ta danh dau vi tri EMPTY nay va ket thuc.*/
			index_EMPTY_DELETED = n;
			return false;
		}
		else if (m_array_datas[n].m_state == DELETED && m_array_datas[index_EMPTY_DELETED].m_state != DELETED)
		/* Neu gap vi tri DELETED dau tien trong day.*/
		{
			/* Thi ta danh dau vi tri nay va tiep tuc lap.*/
			index_EMPTY_DELETED = n;
		}
	}

	/* Dung tham do ma van khong tim ra du lieu can tim va cung khong phat hien ra vi tri DELETED.*/
	return false;
}

int CDictionary::probing(int & position, int & number)
{
	return ((position + number) % SIZE);
}

int CDictionary::hash(const typeOfKey & key)
{
	return key % SIZE;
}
