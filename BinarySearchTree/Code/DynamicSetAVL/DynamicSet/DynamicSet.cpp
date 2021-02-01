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
	bool is_taller = true;
	insert(data_parameter, key_parameter, m_root, is_taller);
}

void CDynamicSet::insert(const typeOfData & data_parameter, const typeOfKey & key_parameter, CNope * &root_ptr, bool &is_taller)
{
	if (root_ptr == NULL)
	/* Neu cay rong.*/
	{
	    root_ptr = new CNope(data_parameter, key_parameter);
		is_taller = true;
	}
	else if (key_parameter < root_ptr->m_key)
	/* Neu khoa truyen vao nho hon khoa o dinh.*/
	{
		/* Thi ta them vao cay con trai.*/
		insert(data_parameter, key_parameter, root_ptr->m_left, is_taller);

		if (is_taller)
		/* Neu cay con tang chieu cao va du dieu kien xet tiep.*/
		{
			switch (root_ptr->m_balance)
			{
				case EH:
					root_ptr->m_balance = LH;
					is_taller = true;
					break;
			
				case RH:
					root_ptr->m_balance = EH;
					is_taller = false;
					break;
				
				case LH:
					rotationWhenLeftChildHigherAfterInsert(root_ptr);
					is_taller = false;
					break;
			}
		}
	}
	else if (key_parameter > root_ptr->m_key)
	/* Neu khoa truyen vao lon hon khoa o dinh.*/
	{
		/* Thi ta them vao cay con phai.*/
		insert(data_parameter, key_parameter, root_ptr->m_right, is_taller);

		if (is_taller)
		{
		 	switch (root_ptr->m_balance)
		 	{
		 		case EH:
					root_ptr->m_balance = RH;
					is_taller = true;
		 			break;
		 	
		 		case LH:
					root_ptr->m_balance = EH;
					is_taller = false;
		 			break;
		 		
		 		case RH:
					rotationWhenRightChildHigherAfterInsert(root_ptr);
					is_taller = false;
		 			break;
		 	}
		}
	}
}

void CDynamicSet::rotationWhenLeftChildHigherAfterInsert(CNope * &root_ptr)
{
	switch (root_ptr->m_left->m_balance)
	{
		case LH:
			rightRotation(root_ptr);
			root_ptr->m_balance = EH;
			root_ptr->m_right->m_balance = EH;
			break;
	
		case RH:
			leftRotationLeftChildThenRightRotationRoot(root_ptr);

			switch (root_ptr->m_balance)
			{
				case LH:
					root_ptr->m_left->m_balance = EH;
					root_ptr->m_right->m_balance = RH;
					break;
			
				case RH:
					root_ptr->m_left->m_balance = LH;
					root_ptr->m_right->m_balance = EH;
					break;
				
				case EH:
					root_ptr->m_left->m_balance = EH;
					root_ptr->m_right->m_balance = EH;
					break;
			}

			root_ptr->m_balance = EH;
			break;
	}
}

void CDynamicSet::rotationWhenRightChildHigherAfterInsert(CNope * &root_ptr)
{
	switch (root_ptr->m_right->m_balance)
	/* Xet trang thai cua cay con phai.*/
	{
		case RH: /* Lech han phai.*/
			leftRotation(root_ptr);
			root_ptr->m_balance = EH;
			root_ptr->m_left->m_balance = EH;
			break;
	
		case LH: /* Lech trong phai.*/
			rightRotationRightChildThenLeftRotationRoot(root_ptr);

			switch (root_ptr->m_balance)
			{
				case LH:
					root_ptr->m_left->m_balance = EH;
					root_ptr->m_right->m_balance = RH;
					break;
			
				case EH:
					root_ptr->m_left->m_balance = EH;
					root_ptr->m_right->m_balance = EH;	
					break;
				
				case RH:
					root_ptr->m_left->m_balance = LH;
					root_ptr->m_right->m_balance = EH;
					break;
			}

			root_ptr->m_balance = EH;
			break;
	}
}

void CDynamicSet::rotationWhenRightChildShorterAfterDelete(CNope * &root_ptr, bool &is_shorter)
{
	switch (root_ptr->m_balance)
	{
		case LH:
			rotationWhenLeftChildHigherAfterInsert(root_ptr);
			is_shorter = true;
			break;
	
		case EH:
			root_ptr->m_balance = LH;
			is_shorter = false;
			break;
		
		case RH:
			root_ptr->m_balance = EH;
			is_shorter = true;
			break;
	}
}



void CDynamicSet::rotationWhenLeftChildShorterAfterDelete(CNope * &root_ptr, bool &is_shorter)
{
	switch (root_ptr->m_balance)
	{
		case LH:
			/* Dang LH va cay trai ngan di 1 thi tro thanh EH.
			 * Dong thoi cay moi ngan hon cay ban dau 1.
			 * */
			root_ptr->m_balance = EH;
			is_shorter = true;
			break;
	
		case EH:
			root_ptr->m_balance = RH;
			is_shorter = false;
			break;
		
		case RH:
			/* Dang RH va cay con trai ngan di 1 thi tro thanh lech phai.
			 * Can xoay cay ve ben trai.
			 * Cay moi se ngan hon cay ban dau 1.
			 * */
			rotationWhenRightChildHigherAfterInsert(root_ptr);
			is_shorter = true;
			break;
	}
}

																	/* Ham delete.*/
void CDynamicSet::deleteElementByKey(const typeOfKey & key)
{
	bool is_shorter = true;
	deleteElementByKey(key, m_root, is_shorter);
}

void CDynamicSet::deleteElementByKey(const typeOfKey & key, CNope * &root_ptr, bool &is_shorter)
{
	if (root_ptr != NULL)
	{
	    if (key < root_ptr->m_key)
	    /* Neu khoa can xoa nho hon khoa o dinh thi ta chay sang cay con trai.*/
	    {
	    	deleteElementByKey(key, root_ptr->m_left, is_shorter);

	    	/* Quay ve dinh cha.*/
			if (is_shorter)
			{
				/* Ta vua xoa dinh o cay con trai.*/
			    rotationWhenLeftChildShorterAfterDelete(root_ptr, is_shorter);
			}
			
	    }
	    else if (key > root_ptr->m_key)
	    /* Neu khoa can xoa lon hon khoa o dinh thi ta chay sang cay con phai.*/
	    {
	    	deleteElementByKey(key, root_ptr->m_right, is_shorter);

	    	/* Quay ve dinh cha.*/
			if (is_shorter)
			{
				/* Ta vua xoa dinh o cay con phai.*/
			    rotationWhenRightChildShorterAfterDelete(root_ptr, is_shorter);
			}
	    }
	    else
	    /* Neu gap khoa can xoa.*/
	    {
	    	delNope(root_ptr, is_shorter);
	    }
	}
}

/* Ham xoa phan tu co khoa nho nhat trong tap.*/
void CDynamicSet::delNope(CNope * &nope_need_del, bool &is_shorter)
{
	if (nope_need_del->m_left == NULL)
	{
		CNope *old_ptr = nope_need_del;
		nope_need_del = nope_need_del->m_right;
		delete old_ptr;
		old_ptr = NULL;
		is_shorter = true;
	}
	else if (nope_need_del->m_right == NULL)
	{
		CNope *old_ptr = nope_need_del;
		nope_need_del = nope_need_del->m_left;
		delete old_ptr;
		old_ptr = NULL;
		is_shorter = true;
	}
	else
	{
		deleteMin(nope_need_del->m_right, nope_need_del, is_shorter);

		if (is_shorter)
		{
		    rotationWhenRightChildShorterAfterDelete(nope_need_del, is_shorter);
		}
	}
}

void CDynamicSet::deleteMin(CNope * &root_ptr, CNope * &take_nope_min, bool &is_shorter)
{
	if (root_ptr->m_left == NULL)
	{
		take_nope_min->m_data = root_ptr->m_data;
		take_nope_min->m_key = root_ptr->m_key;

		CNope *old_ptr = root_ptr;
		root_ptr = root_ptr->m_right;

		is_shorter = true;

		delete old_ptr;
		old_ptr = NULL;
	}
	else
	{
		deleteMin(root_ptr->m_left, take_nope_min, is_shorter);

		if (is_shorter)
		{
		    rotationWhenLeftChildShorterAfterDelete(root_ptr, is_shorter);
		}
	}
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

void CDynamicSet::leftRotationLeftChildThenRightRotationRoot(CNope * &root_ptr)
{
	leftRotation(root_ptr->m_left);
	rightRotation(root_ptr);
}

void CDynamicSet::rightRotationRightChildThenLeftRotationRoot(CNope * &root_ptr)
{
	rightRotation(root_ptr->m_right);
	leftRotation(root_ptr);
}

