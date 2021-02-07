#include "PriorityQueue.h"
void swapTree(CNope * &root_ptr_1, CNope * &root_ptr_2)
{
	CNope * center_ptr = root_ptr_1;
	root_ptr_1 = root_ptr_2;
	root_ptr_2 = center_ptr;
}

CNope * mergeTree(CNope * &root_ptr_1, CNope * &root_ptr_2)
{
	/* Cau lenh nay dam bao root_ptr_1 luon tro toi dinh co uu tien nho hon va luon khac NULL.*/
	if ( ( (root_ptr_2 != NULL) && (root_ptr_1 != NULL) && (root_ptr_1->m_priority >= root_ptr_2->m_priority) ) || (root_ptr_1 == NULL) )
	{
	    swapTree(root_ptr_1, root_ptr_2);
	}

	/* Cau lenh nay ghep noi cac dinh tren duong ben phai.*/
	if (root_ptr_1 != NULL)
	{
	    root_ptr_1->m_right = mergeTree(root_ptr_1->m_right, root_ptr_2);
	}
	
	/* Cau lenh nay duoc goi khi de quy xong, dung de doi cho cay con trai va cay con phai.*/
	if (root_ptr_1 != NULL)
	{
		if (root_ptr_1->m_right != NULL)
		{
			swapTree(root_ptr_1->m_right, root_ptr_1->m_left);
		}
	}
	
	return root_ptr_1;
}

CPriorityQueue::CPriorityQueue()
{
	m_root = NULL;
}

void makeEmpty(CNope * &root_ptr)
{
	if (root_ptr != NULL)
	{
	    makeEmpty(root_ptr->m_left);
		makeEmpty(root_ptr->m_right);
		delete root_ptr;
		root_ptr = NULL;
	}
}

CPriorityQueue::~CPriorityQueue()
{
	makeEmpty(m_root);
}

void CPriorityQueue::insert(const typeOfData &data_parameter, const typeOfPriority &priority_parameter)
{
	CNope * root_insert = new CNope(data_parameter, priority_parameter);
	
	mergeTree(m_root, root_insert);
}

void CPriorityQueue::insert(CNope &nope_parameter)
{
	CNope * root_insert = &nope_parameter;

	mergeTree(m_root, root_insert);
}

CNope CPriorityQueue::deleteMin()
{
	CNope * old_root = m_root;

	m_root = mergeTree(m_root->m_left, m_root->m_right);

	CNope take_nope(old_root->m_data, old_root->m_priority);
	delete old_root;
	old_root = NULL;

	return take_nope;
}

CNope CPriorityQueue::findMin()
{
	return *m_root;
}

void CPriorityQueue::decreaseKey(CNope *root_ptr, const typeOfPriority &key)
{
	
}

