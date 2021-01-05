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

/* Kiem tra xem tap co rong khong.*/
bool CDynamicSet::isSetEmpty()
{
	return m_root == NULL;
}

/* Ham insert.*/
void CDynamicSet::insert(const typeOfData & data_parameter, const typeOfKey & key_parameter)
{
	insert(data_parameter, key_parameter, m_root);
}

void CDynamicSet::insert(const typeOfData & data_parameter, const typeOfKey & key_parameter, CNope * &root_ptr)
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
		return insert(data_parameter, key_parameter, root_ptr->m_left);
	}
	else if (key_parameter > root_ptr->m_key)
	/* Neu khoa truyen vao lon hon khoa o dinh.*/
	{
		/* Thi ta them vao cay con phai.*/
		return insert(data_parameter, key_parameter, root_ptr->m_right);
	}
}

/* Ham delete.*/
void CDynamicSet::deleteElementByKey(const typeOfKey & key)
{
	deleteElementByKey(key, m_root);
}

void CDynamicSet::deleteElementByKey(const typeOfKey & key, CNope * &root_ptr)
{
	if (key < root_ptr->m_key)
	/* Neu khoa can xoa nho hon khoa o dinh.*/
	{
		/* Thi ta chay xuong cay con trai.*/
		deleteElementByKey(key, root_ptr->m_left);
	}
	else if (key > root_ptr->m_key)
	/* Neu khoa can xoa lon hon khoa o dinh.*/
	{
		/* Thi ta chay xuong cay con phai.*/
		deleteElementByKey(key, root_ptr->m_right);
	}
	else if (root_ptr->m_left != NULL && root_ptr->m_right != NULL)
	/* Neu khoa can xoa bang khoa o dinh, dong thoi cay con trai
	 * va cay con phai deu khong rong.*/
	{
		/* Tim phan tu co khoa be nhat trong cay con phai,
		 * dong thoi xoa no di.*/
		CNope *take_element = deleteMin(root_ptr->m_right);

		/* Gan gia tri o dinh can xoa bang gia tri cua phan tu co 
		 * khoa be nhat trong cay con phai.*/
		root_ptr->m_data = take_element->m_data;
		root_ptr->m_key = take_element->m_key;
	}
	else if (root_ptr->m_left == NULL)
	/* Neu cay con trai rong.*/
	{
		CNope *old_root = root_ptr;
		root_ptr = root_ptr->m_right;
		delete old_root;
	}
	else
	/* Neu cay con phai rong.*/
	{
		CNope *old_root = root_ptr;
		root_ptr = root_ptr->m_left;
		delete old_root;
	}
}

/* Ham xoa phan tu co khoa nho nhat trong tap.*/
CNope * CDynamicSet::deleteMin()
{
	deleteMin(m_root);
}

CNope * CDynamicSet::deleteMin(CNope * &root_ptr)
{
	while (root_ptr->m_left != NULL)
	/* Chay cho den khi gap la ngoai cung ben trai cua cay.*/
	{
		return deleteMin(root_ptr->m_left);
	} // End while.

	CNope *take_element = new CNope(root_ptr->m_data, root_ptr->m_key); // lay du lieu.

	CNope *old_left = root_ptr; // dinh vi con tro cu.

	root_ptr = root_ptr->m_right; // noi voi cay con phai.

	delete old_left; // thu hoi bo nho.

	return take_element;
}

/* Ham tim kiem.*/
bool CDynamicSet::search(const typeOfKey & key, typeOfData &take_data)
{
	search(key, take_data, m_root);
}

bool CDynamicSet::search(const typeOfKey & key, typeOfData &take_data, CNope * &root_ptr)
{
	if (root_ptr != NULL)
	/* Neu cay khong rong.*/
	{
		if (root_ptr->m_key == key)
		/* Neu gap dinh can tim.*/
		{
			take_data = root_ptr->m_data;
			return true;
		}
		else if (key < root_ptr->m_key)
		/* Neu khoa can tim nho hon khoa o dinh.*/
		{
			/* Thi ta tim o cay con trai.*/
			return search(key, take_data, root_ptr->m_left);
		}
		else if (key > root_ptr->m_key)
		/* Neu khoa can tim lon hon khoa o dinh.*/
		{
			/* Thi ta tim o cay con phai.*/
			return search(key, take_data, root_ptr->m_right);
		}
	}
	else 
	/* Neu cay rong.*/
	{
		return false;
	}
}

/* Ham tim kiem phan tu co khoa nho nhat trong tap.*/
typeOfData CDynamicSet::min()
{
	min(m_root);
}

typeOfData CDynamicSet::min(CNope * &root_ptr)
{
	while (root_ptr->m_left != NULL)
	/* Chay cho den la ngoai cung ben trai cua cay.*/
	{
		return min(root_ptr->m_left);
	} // End while.

	return root_ptr->m_data;
}

/* Ham tim kiem phan tu co khoa lon nhat trong tap.*/
typeOfData CDynamicSet::max()
{
	max(m_root);
}

typeOfData CDynamicSet::max(CNope * &root_ptr)
{
	while (root_ptr->m_right != NULL)
	/* Chay cho den la ngoai cung ben phai cua cay.*/
	{
		return max(root_ptr->m_right);
	} // End while.

	return root_ptr->m_data;
}
