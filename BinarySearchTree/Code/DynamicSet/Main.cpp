#include <iostream>
#include <string>
#include "Nope/Nope.h"
#include "DynamicSet/DynamicSet.h"
using namespace std;

void thuHamDelete()
{
	CDynamicSet *set = new CDynamicSet();
	set->insert(5, 5);
	set->insert(2, 2);
	set->insert(3, 3);
	set->insert(7, 7);
	set->insert(6, 6);
	set->insert(11, 11);
	set->insert(8, 8);
	set->insert(12, 12);
	set->insert(9, 9);
	
	int a;
	/* Kiem tra xem phan tu 2 con khong.*/
	if (set->search(1,a))
	/* Neu con.*/
	{
	    cout << "con." << endl;
		cout << "Gia tri la: " << a << endl;
	}
	else
	/* Neu khong con.*/
	{
		cout << "Khong con." << endl;
	}
	cout << endl;

	/* Xoa phan tu 2.*/
	set->deleteElementByKey(1);

	/* Kiem tra xem phan tu 2 con khong.*/
	if (set->search(1,a))
	/* Neu con.*/
	{
	    cout << "con." << endl;
	}
	else
	/* Neu khong con.*/
	{
		cout << "Khong con." << endl;
	}
	cout << endl;

	/* Kiem tra xem phan tu 2 con khong.*/
	if (set->search(1,a))
	/* Neu con.*/
	{
	    cout << "con." << endl;
	}
	else
	/* Neu khong con.*/
	{
		cout << "Khong con." << endl;
	}
	cout << endl;


	delete set;
	
}

void thu()
{
	CDynamicSet *set = new CDynamicSet();
	set->insert(4, 4);
	set->insert(3, 5);

	int take_data;
	if (set->search(4, take_data))
	/* Neu tim thay phan tu co khoa la 4.*/
	{
	 	cout << "Tim thay phan tu."  << endl;
	 	cout << "Du lieu: " << take_data << endl;	
	}

	if (set->search(5, take_data))
	/* Neu tim thay phan tu co khoa la 5.*/
	{
	    cout << "Tim thay phan tu." << endl;
		cout << "Du lieu: " << take_data << endl;
	}

	set->insert(132534, 4);
	set->insert(652452, 3);
	set->insert(54333, 5);
	delete set;
}

void kiemtraconstructor()
{
	CDynamicSet *set = new CDynamicSet();
	set->insert(5, 5);
	set->insert(2, 2);
	set->insert(3, 3);
	set->insert(7, 7);
	set->insert(6, 6);
	set->insert(11, 11);
	set->insert(8, 8);
	set->insert(12, 12);
	set->insert(9, 9);
	int a;
	
	CDynamicSet *set1 = new CDynamicSet();

	set1->copyTree(set1->m_root, set->m_root);

	/* Kiem tra.*/
	if (set1->search(5, a))
	/* Neu tim thay phan tu 5 trong tap set1.*/
	{
	    cout << "Tim thay va gia tri la: " << a << endl;
	}

	/* Them phan tu 100 vao set1.*/
	set1->insert(100, 100);
	if (set1->search(100, a))
	/* Neu tim thay phan tu 100 trong tap set1.*/
	{
	    cout << "Tim thay va gia tri la: " << a << endl;
	}

	/* Kiem tra tap set.*/
	if (set->search(100, a))
	/* Neu tim thay phan tu 100 trong tap set.*/
	{
	    cout << "Tim thay va gia tri la: " << a << endl;
	}
}

void hihi()
{
	/*comment*/
	CDynamicSet set1;
	set1.insert(3, 3);
	set1.insert(4, 4);
	int a;

	CDynamicSet set2;
	set2 = set1;
	
	if (set2.search(3, a))
	/* Neu ton tai phan tu co khoa la 3.*/
	{
	    cout << "Ton tai." << endl;
	}
	else
	/* Neu khong ton tai.*/
	{
		cout << "Khong ton tai." << endl;
	}
	
}

int main(int argc, char *argv[])
{
	CDynamicSet *set = new CDynamicSet();
	set->insert(5, 5);
	set->insert(2, 2);
	set->insert(3, 3);
	set->insert(7, 7);
	set->insert(6, 6);
	set->insert(11, 11);
	set->insert(8, 8);
	set->insert(12, 12);
	set->insert(9, 9);
	int a;
	
	CDynamicSet *set1 = new CDynamicSet();
	return 0;
}
