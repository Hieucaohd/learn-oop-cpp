#include "HuffmanCode.h"

CPriorityQueue* frequencyOfCharater(string xau)
{
	CPriorityQueue *pri_queue = new CPriorityQueue();

	/* Khoi tao mang mang de danh dau vi tri cac ki tu giong
	 * nhau trong xau.*/
	int mang_danh_dau[xau.length()];	

	/* Cac vi tri chua bi danh dau thi ta se gan gia tri bang -1.*/
	for (int i = 0; i < xau.length(); i++)
	{
		mang_danh_dau[i] = -1;
	}

	for (int index = 0; index < xau.length(); index++)
	{
		/* Lay ki tu can dem.*/
		char ki_tu = xau[index];
		int dem = 0; // bien dem so lan ki tu xuat hien trong xau.

		for (int run = index; run < xau.length(); run++)
		{
			if (xau[run] == ki_tu && mang_danh_dau[run] == -1)
			/* Neu gap ki tu can dem va vi tri cua ki tu nay chua bi danh dau.*/
			{
			 	dem += 1;
				/* Ta se danh dau vi tri da dem bang index dau tien cua ki tu trong xau.*/
			 	mang_danh_dau[run] = index;	
			}
		}

		if (dem != 0)
		/* Neu bien dem khac 0 (tuc ki tu can dem).*/
		{
		    pri_queue->insert(xau[index], dem);
		}
	}
	return pri_queue;
}



CPriorityQueue* makeTree(string xau)
{
	CPriorityQueue *pri_queue = frequencyOfCharater(xau);

	int length_of_priQueue = pri_queue->lengthOfPriQueue();

	for (int i = 1; i <= length_of_priQueue - 1; i++)
	{
		CNope left_nope;
		CNope right_nope;
		left_nope = pri_queue->deleteMin();
		right_nope = pri_queue->deleteMin();
		CNope *left_nope_ptr = &left_nope;
		CNope *right_nope_ptr = &right_nope;

		CNope source_nope;
		source_nope.m_priority = left_nope.m_priority + right_nope.m_priority;
		copyTree(left_nope_ptr, source_nope.m_left);
		copyTree(right_nope_ptr, source_nope.m_right);

		pri_queue->insert(source_nope);
	}

	return pri_queue;
}