#include <iostream>
#include <string>
#include <vector>

#include "PriorityQueue/PriorityQueue.h"
#include "Nope/Nope.h"
#include "HuffmanCode/HuffmanCode.h"
#include "Stack/Stack.h"

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
	string xau = "ab";
	cout << xau << endl;
	cout << maHoaXau(xau) << endl;
}

void thu5()
{
	string xau;
	cin >> xau;
	CStack stack_1;
	stack_1.push(xau);
	cout << stack_1.pop() << endl;
}

void thu6()
{
	string xau = "anh yeu em";
	CStack stack_string;
	string ma_hoa;
	/* Tao ra cay nhi phan chua cac dinh la la cac ki tu va ma hoa tuong ung cua chung.*/
	CPriorityQueue *pri_queue = makeTree(xau);
	CNope take_nope;
	take_nope = pri_queue->deleteMin();
	CNope *nope_ptr = &take_nope;
	
	/* Khoi tao mang de luu cac ki tu va ma hoa tuong ung cua chung.*/
	int so_luong_phan_tu = frequencyOfCharater(xau)->lengthOfPriQueue();
	CCodeAndCharacter array_ma_code[so_luong_phan_tu];
	int dem = 0;

	/* Luu cac ki tu va ma hoa tuong ung cua chung vao mang array_ma_code.*/
	codeOfCharacter(nope_ptr, stack_string, ma_hoa, array_ma_code, dem);

	cout << endl;

	for (int i = 0; i < so_luong_phan_tu; i++)
	{
		cout << array_ma_code[i].m_ki_tu << " - " << array_ma_code[i].m_ma_code << endl;
	}
}

void thu7()
{
	string xau = "abcdefg";
	CPriorityQueue *pri_queue = makeTree(xau);
	cout << pri_queue->findMin().m_right->m_right->m_left  << endl;
}

int main(int argc, char *argv[])
{
	thu4();
	return 0;
}
