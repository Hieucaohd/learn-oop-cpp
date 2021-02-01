#include <iostream>
#include <string>
#include <vector>

#include "Nope/Nope.h"
#include "DynamicSet/DynamicSet.h"

using namespace std;

void themPhanTuVaoTapDong(CDynamicSet *set,const int &number)
{
	for (int i = 0; i < number; i++)
	{
		cout << "Nhap du lieu va khoa: ";
		int key;
		cin >> key;

		set->insert(key, key);
	}
}

void thu()
{
	CDynamicSet *set = new CDynamicSet();
	set->insert(6, 6);
	set->insert(5, 5);
	set->insert(15, 15);
	set->insert(3, 3);
	set->insert(10, 10);
	set->insert(17, 17);
	set->insert(9, 9);
	set->insert(13, 13);

	set->insert(12, 12);

	cout << set->m_root->m_right->m_right->m_right->m_key << endl;
}

void thu1()
{
	CDynamicSet *set = new CDynamicSet();

	set->insert(7,7);
	set->insert(4,4);
	set->insert(15,15);
	set->insert(3,3);
	set->insert(5,5);
	set->insert(10,10);
	set->insert(18,18);
	set->insert(1,1);
	set->insert(8,8);
	set->insert(13,13);
	set->insert(16,16);
	set->insert(14,14);

	set->deleteElementByKey(7);

	cout << set->m_root->m_left->m_left->m_balance << endl;
}

int main(int argc, char *argv[])
{
	thu1();
	return 0;
}
