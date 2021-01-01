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
	if (set->search(7,a))
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
	set->deleteElementByKey(7);

	/* Kiem tra xem phan tu 2 con khong.*/
	if (set->search(7,a))
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
	if (set->search(6,a))
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

int main(int argc, char *argv[])
{
	return 0;
}
