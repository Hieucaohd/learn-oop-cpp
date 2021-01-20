#include <iostream>
#include <string>
#include <vector>

#include "PriorityQueue/PriorityQueue.h"
#include "Nope/Nope.h"
#include "HuffmanCode/HuffmanCode.h"

using namespace std;

void thu()
{
	CPriorityQueue *pri_queue = new CPriorityQueue();
	pri_queue->insert('a', 1);
	pri_queue->insert('b', 2);
	pri_queue->insert('c', 3);

	cout << pri_queue->findMin().m_priority << endl;

	cout << pri_queue->deleteMin().m_priority << endl;
	cout << pri_queue->deleteMin().m_priority << endl;
	cout << pri_queue->deleteMin().m_priority << endl;
}

void thu1()
{
	CNope nope_1('a', 1);
	nope_1.m_left = new CNope('l', 2);
	nope_1.m_left->m_left = new CNope('k', 3);
	nope_1.m_left->m_right = new CNope('t', 4);

	nope_1.m_right = new CNope('r', 2);

	CNope nope_2;
	nope_2 = nope_1;
	
	cout << "Muc 1: " << endl;
	cout << nope_2.m_data << endl;
	cout << nope_2.m_priority << endl;

	cout << "Muc 2: " << endl;
	cout << nope_2.m_left->m_data << endl;
	cout << nope_2.m_left->m_priority << endl;
	cout << nope_2.m_right->m_data << endl;
	cout << nope_2.m_right->m_priority << endl;

	cout << "Muc 3: " << endl;
	cout << nope_2.m_left->m_left->m_data << endl;
	cout << nope_2.m_left->m_left->m_priority << endl;

	cout << nope_2.m_left->m_right->m_data << endl;
	cout << nope_2.m_left->m_right->m_priority << endl;

	cout << "Kiem tra phu thuoc." << endl;
	nope_2.m_left->m_right->m_priority = 66;
	cout << nope_2.m_left->m_right->m_priority << endl;
	cout << nope_1.m_left->m_right->m_priority << endl;



}

void thu2()
{
	CNope *nopes_ptr = new CNope[20];
	cout << nopes_ptr[1].m_data << endl;
}

void thu3()
{
	string xau;
	cin >> xau;
	CPriorityQueue *pri_queue = makeTree(xau);

	cout << "So phan tu cua hang uu tien: " << pri_queue->lengthOfPriQueue() << endl;
	cout << pri_queue->findMin().m_right->m_priority << endl;
}

void themKiTu(string &xau, const int &so_luong, const char &ki_tu)
{
	for (int i = 0; i < so_luong; i++)
	{
		xau.push_back(ki_tu);
	}
}

void thu4()
{
	string xau = "haehehh";

	cout << xau << endl;
	cout << maHoaXau(xau) << endl;
}

int main(int argc, char *argv[])
{
	thu4();
	return 0;
}
