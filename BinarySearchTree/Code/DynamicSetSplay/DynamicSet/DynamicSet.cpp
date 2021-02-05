#include "DynamicSet.h"

/* Constructor.*/
void copyTree(const CNope * from_root_ptr, CNope * &to_root_ptr)
{
	if (from_root_ptr != NULL)
	{
		to_root_ptr = new CNope(from_root_ptr->m_data, from_root_ptr->m_key);
		copyTree(from_root_ptr->m_left, to_root_ptr->m_left);
		copyTree(from_root_ptr->m_right, to_root_ptr->m_right);
	}
	else
	{
		return;
	}
}

CDynamicSet::CDynamicSet()
{
	m_root = NULL;
}

CDynamicSet::CDynamicSet(const CDynamicSet & set)
{
	m_root = NULL;
	copyTree(set.m_root, this->m_root);
}

CDynamicSet::CDynamicSet(const CDynamicSet * set_ptr)
{
	m_root = NULL;
	copyTree(set_ptr->m_root, this->m_root);
}

CDynamicSet CDynamicSet::operator = (const CDynamicSet & set)
{
	if (!isSetEmpty())
	/* Neu tap cu khong rong.*/
	{
	    /* Thi ta phai xoa tap cu di.*/
		makeEmpty(m_root);
	}

	copyTree(set.m_root, this->m_root);
	return *this;
}








/* Destructor.*/
CDynamicSet::~CDynamicSet()
{
	makeEmpty(m_root);
}

void CDynamicSet::makeEmpty(CNope * &root_ptr)
{
	if (root_ptr != NULL)
	/* Neu cay khong rong.*/
	{
	    makeEmpty(root_ptr->m_left);
		makeEmpty(root_ptr->m_right);
		delete root_ptr;
		root_ptr = NULL;
	}
}











/* Ham insert.*/
void CDynamicSet::insert(const typeOfData & data_parameter, const typeOfKey & key_parameter)
{
	string way;
	insert(data_parameter, key_parameter, m_root, way);
}

void CDynamicSet::insert(const typeOfData & data_parameter, const typeOfKey & key_parameter, CNope * &root_ptr, string &way)
{
	if (root_ptr == NULL)
	/* Neu cay rong.*/
	{
	    root_ptr = new CNope(data_parameter, key_parameter);
	}
	else if (key_parameter < root_ptr->m_key)
	/* Neu khoa truyen vao nho hon khoa o dinh.*/
	{
		/* Thi ta them vao cay con trai.*/
		insert(data_parameter, key_parameter, root_ptr->m_left, way);

		way.push_back('0');

		if (way == "00")
		/* Neu la zig-zig.*/
		{
			rightRotation(root_ptr);
			rightRotation(root_ptr);
			way.erase(0, way.length());
		}
		else if (way == "10")
		/* Neu la zig-zag.*/
		{
			leftRotation(root_ptr->m_left);
			rightRotation(root_ptr);
			way.erase(0, way.length());
		}
		else if (root_ptr == m_root)
		/* Neu la zig.*/
		{
			rightRotation(root_ptr);
			way.erase(0, way.length());
		}
	}
	else if (key_parameter > root_ptr->m_key)
	/* Neu khoa truyen vao lon hon khoa o dinh.*/
	{
		/* Thi ta them vao cay con phai.*/
		insert(data_parameter, key_parameter, root_ptr->m_right, way);

		way.push_back('1');

		if (way == "11")
		/* Neu la zag-zag.*/
		{
			leftRotation(root_ptr);
			leftRotation(root_ptr);
			way.erase(0, way.length());
		}
		else if (way == "01")
		/* Neu la zag-zig.*/
		{
			rightRotation(root_ptr->m_right);
			leftRotation(root_ptr);
			way.erase(0, way.length());
		}
		else if (root_ptr == m_root)
		/* Neu la zag.*/
		{
			leftRotation(root_ptr);
			way.erase(0, way.length());
		}
	}
}









/* Ham delete.*/
typeOfData CDynamicSet::deleteElementByKey(const typeOfKey & key)
{
	typeOfData take_data;
	deleteElementByKey(key, m_root, take_data);

	return take_data;
}

void CDynamicSet::deleteElementByKey(const typeOfKey & key, CNope * &root_ptr, typeOfData &take_data)
{
	if (search(key, take_data))
	{
		CNope take_nope;
		string way;
		min(root_ptr->m_right, take_nope, way, root_ptr->m_right);

		root_ptr->m_right->m_left = root_ptr->m_left;
		
		CNope * old_ptr = root_ptr;
		root_ptr = root_ptr->m_right;

		delete old_ptr;
		old_ptr = NULL;
	}
}








/* Ham tim kiem (ham search).*/
bool CDynamicSet::search(const typeOfKey & key, typeOfData &take_data)
{
	string way;
	bool is_found;
	search(key, take_data, m_root, way, is_found);

	return is_found;
}

void CDynamicSet::search(const typeOfKey & key, typeOfData &take_data, CNope * &root_ptr, string &way, bool &is_found)
{
	if (root_ptr != NULL)
	/* Neu cay khong rong.*/
	{
		if (root_ptr->m_key == key)
		/* Neu gap dinh can tim.*/
		{
			take_data = root_ptr->m_data;
			is_found = true;
		}
		else if (key < root_ptr->m_key)
		/* Neu khoa can tim nho hon khoa o dinh.*/
		{
			/* Thi ta tim o cay con trai.*/
			search(key, take_data, root_ptr->m_left, way, is_found);

			way.push_back('0');

			if (way == "00")
			/* Neu la zig-zig.*/
			{
				rightRotation(root_ptr);
				rightRotation(root_ptr);
				way.erase(0, way.length());
			}
			else if (way == "10")
			/* Neu la zig-zag.*/
			{
				leftRotation(root_ptr->m_left);
				rightRotation(root_ptr);
				way.erase(0, way.length());
			}
			else if (root_ptr == m_root)
			/* Neu la zig.*/
			{
				rightRotation(root_ptr);
				way.erase(0, way.length());
			}
		}
		else if (key > root_ptr->m_key)
		/* Neu khoa can tim lon hon khoa o dinh.*/
		{
			/* Thi ta tim o cay con phai.*/
			search(key, take_data, root_ptr->m_right, way, is_found);

			way.push_back('1');

			if (way == "11")
			/* Neu la zag-zag.*/
			{
				leftRotation(root_ptr);
				leftRotation(root_ptr);
				way.erase(0, way.length());
			}
			else if (way == "01")
			/* Neu la zag-zig.*/
			{
				rightRotation(root_ptr->m_right);
				leftRotation(root_ptr);
				way.erase(0, way.length());
			}
			else if (root_ptr == m_root)
			/* Neu la zag.*/
			{
				leftRotation(root_ptr);
				way.erase(0, way.length());
			}
		}
	}
	else 
	/* Neu cay rong.*/
	{
		is_found = false;
	}
}






/* Ham tim kiem phan tu co khoa nho nhat trong tap.*/
CNope CDynamicSet::min()
{
	CNope take_nope;
	string way;
	min(m_root, take_nope, way, m_root);

	return take_nope;
}

void CDynamicSet::min(CNope * &root_ptr, CNope &take_nope, string &way, const CNope * initial_nope_ptr)
{
	if (root_ptr->m_left == NULL)
	/* Neu gap dinh khong co cay con trai.*/
	{
		take_nope.m_data = root_ptr->m_data;
		take_nope.m_key = root_ptr->m_key;
	}
	else
	{
		min(root_ptr->m_left, take_nope, way, initial_nope_ptr);

		way.push_back('0');

		if (way == "00")
		/* Neu la zig-zig.*/
		{
			rightRotation(root_ptr);
			rightRotation(root_ptr);
			way.erase(0, way.length());
		}
		else if (root_ptr == initial_nope_ptr)
		/* Neu la zig.*/
		{
			rightRotation(root_ptr);
			way.erase(0, way.length());
		}
	}
}






/* Ham tim kiem phan tu co khoa lon nhat trong tap.*/
CNope CDynamicSet::max()
{
	CNope take_nope;
	string way;
	max(m_root, take_nope, way, m_root);

	return take_nope;
}

void CDynamicSet::max(CNope * &root_ptr, CNope &take_nope, string &way,const CNope * initial_nope_ptr)
{
	if (root_ptr->m_right == NULL)
	/* Neu gap dinh khong co cay con trai.*/
	{
		take_nope.m_data = root_ptr->m_data;
		take_nope.m_key = root_ptr->m_key;
	}
	else
	{
		max(root_ptr->m_right, take_nope, way, initial_nope_ptr);

		way.push_back('0');

		if (way == "00")
		/* Neu la zig-zig.*/
		{
			leftRotation(root_ptr);
			leftRotation(root_ptr);
			way.erase(0, way.length());
		}
		else if (root_ptr == initial_nope_ptr)
		/* Neu la zig.*/
		{
			leftRotation(root_ptr);
			way.erase(0, way.length());
		}
	}
}








/* Cac ham xoay.*/
void CDynamicSet::rightRotation(CNope * &root_ptr)
{
	CNope *Q = root_ptr;
	root_ptr = root_ptr->m_left;
	Q->m_left = root_ptr->m_right;
	root_ptr->m_right = Q;
}

void CDynamicSet::leftRotation(CNope * &root_ptr)
{
	CNope *Q = root_ptr;
	root_ptr = root_ptr->m_right;
	Q->m_right = root_ptr->m_left;
	root_ptr->m_left = Q;
}





/* Kiem tra xem tap co rong khong.*/
bool CDynamicSet::isSetEmpty()
{
	return m_root == NULL;
}
