#include <iostream>
#include <string>
#include <vector>

#include "Nope/Nope.h"
#include "PriorityQueue/PriorityQueue.h"

using namespace std;

void swap(CNope * &root_ptr_1, CNope * root_ptr_2)
{
	root_ptr_1 = new CNope(100, 100);
}

void thu()
{
	CNope * root;
	root = new CNope(12, 12);
	root->m_left = new CNope(1, 1);
	root->m_right = new CNope(2, 2);

	swap(root->m_left, root->m_right);

	cout << root->m_left->m_data << endl;
}

void thu1()
{
	CNope * root;
	root = new CNope(12, 12);
	root->m_left = new CNope(1, 1);
	root->m_right = new CNope(2, 2);

	CNope * new_root_left = root->m_left;

	new_root_left = root->m_right;

	cout << root->m_left->m_data << endl;
}

void ganConTroHieu(CNope * &to_root_ptr, CNope * &from_root_ptr)
{
	to_root_ptr = from_root_ptr;
}

void thu2()
{
	CNope nope_root;
	CNope * root;
	ganConTroHieu(nope_root.m_right, root);
	root = new CNope(12, 12);
}

void thu3()
{
	CNope * root;
	root = new CNope(12, 12);
	root->m_left = new CNope(1, 1);
	root->m_right = new CNope(2, 2);

	CNope * create_ptr = root->m_left->m_left;
	create_ptr = new CNope(100, 100);

	cout << root->m_left->m_left->m_data << endl;
}

void swapTreeMain(CNope * &root_ptr_1, CNope * &root_ptr_2)
{
    CNope * center_ptr = root_ptr_1;
	root_ptr_1 = root_ptr_2;
    root_ptr_2 = center_ptr;
}

CNope * mergeTreeMain(CNope * &root_ptr_1, CNope * &root_ptr_2)
{   
    /* Cau lenh nay dam bao root_ptr_1 luon tro toi dinh co uu tien nho hon va luon khac NULL.*/
    if ( ( (root_ptr_2 != NULL) && (root_ptr_1 != NULL) && (root_ptr_1->m_priority >= root_ptr_2->m_priority) ) || (root_ptr_1 == NULL) )
    {
        swapTreeMain(root_ptr_1, root_ptr_2);
    }

    /* Cau lenh nay ghep noi cac dinh tren duong ben phai.*/
    if (root_ptr_1 != NULL)
    {
        root_ptr_1->m_right = mergeTreeMain(root_ptr_1->m_right, root_ptr_2);
    }
    
    /* Cau lenh nay duoc goi khi de quy xong, dung de doi cho cay con trai va cay con phai.*/
	if (root_ptr_1 != NULL)
	{
		if (root_ptr_1->m_right != NULL)
		{
			swapTreeMain(root_ptr_1->m_right, root_ptr_1->m_left);
		}
	}
    
    return root_ptr_1;
}   

void thu4()
{
	CNope * root_ptr_1 = new CNope(1, 1);
	CNope * root_ptr_2 = new CNope(2, 2);

	root_ptr_1 = mergeTreeMain(root_ptr_1, root_ptr_2);
}

void thu5()
{
	CPriorityQueue *pri_queue = new CPriorityQueue();

	pri_queue->insert(12, 12);
	pri_queue->insert(1, 1);
	pri_queue->insert(3, 3);
	pri_queue->insert(6, 6);

	pri_queue->deleteMin();
	cout << pri_queue->m_root->m_data << endl;
}

int main(int argc, char *argv[])
{
	thu5();
	return 0;
}
