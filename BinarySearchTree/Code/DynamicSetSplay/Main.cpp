#include <iostream>
#include <string>
#include <vector>

#include "Nope/Nope.h"
#include "DynamicSet/DynamicSet.h"
#include "/home/hieu/CodeTemplate/Stack/Stack.cpp"

using namespace std;

void thu()
{
	CStack<CNope> stack_1;

	CNope nope_1(12, 12);
	CNope left_of_nope_1(1,1);
	CNope right_of_nope_1(2,2);
	nope_1.m_left = &left_of_nope_1;
	nope_1.m_right = &right_of_nope_1;

	stack_1.push(nope_1);
	cout << stack_1.pop().m_left->m_data << endl;
}

void thu1()
{
	CStack<CNope> *stack = new CStack<CNope>();

	CNope *nope_1 = new CNope(1,1);
	nope_1->m_left = new CNope(2,2);
	nope_1->m_right = new CNope(3,3);

	stack->push(*nope_1);

	cout << stack->getTop().m_left->m_data << endl;
}

void thu2()
{
	CDynamicSet *set = new CDynamicSet();

	set->insert(12,12);
	set->insert(12,3);
	set->insert(12,1);
	set->insert(12,0);
	set->insert(12,14);
	set->insert(12,13);

	cout << set->m_root->m_left->m_left->m_left->m_key << endl;
}

void thu3()
{
	CDynamicSet *set = new CDynamicSet();

	set->insert(12,12);
	set->insert(12,3);
	set->insert(12,1);
	set->insert(12,0);
	set->insert(12,14);
	set->insert(12,13);

	cout << set->max().m_key << endl;
	cout << set->m_root->m_left->m_left->m_left->m_left->m_key << endl;
}

void thu4()
{
	CDynamicSet *set = new CDynamicSet();

	set->insert(12,12);
	set->insert(12,3);
	set->insert(1,1);
	set->insert(12,0);
	set->insert(12,14);
	set->insert(12,13);

	typeOfData take_data;

	if (set->search(1, take_data))
	{
		cout << take_data << endl;
	}

	cout << set->m_root->m_key << endl;
	cout << set->m_root->m_left->m_key << endl;
	cout << set->m_root->m_right->m_key << endl;
	cout << set->m_root->m_right->m_left->m_key << endl;
	cout << set->m_root->m_right->m_right->m_key << endl;
	cout << set->m_root->m_right->m_right->m_right->m_key << endl;
}

void thu5()
{
	CDynamicSet *set = new CDynamicSet();

	set->insert(12,12);
	set->insert(888,3);
	set->insert(1,1);
	set->insert(12,0);
	set->insert(12,14);
	set->insert(12,13);

	typeOfData take_data = set->deleteElementByKey(3);
	cout << take_data << endl;

	cout << endl;

	cout << set->m_root->m_right->m_right->m_key << endl;


}

int main(int argc, char *argv[])
{
	system("clear");
	thu5();
	return 0;
}
