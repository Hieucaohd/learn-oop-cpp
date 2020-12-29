#include <iostream>
#include "LinkedList/LinkedList.h"
#include "ListIterator/ListIterator.h"
#include "Nope/Nope.h"
using namespace std;

void printList(CLinkedList &list1)
{
	/* In ra danh sach list1.*/
	cout << "Danh sach: ";
	for (int i = 1; i <= list1.length(); i++)
	{
		cout << list1.findElement(i) << " ";
	}
	cout << endl; // cach dong ra cho dep.
}

void doWithList()
{
	/* Lam viec voi danh sach.*/
	CLinkedList list1; // khai bao danh sach.
	CListIterator iter_list1(list1); // khai bao cong cu lap cho danh sach list1.

	/* Them cac phan tu tu 1 den 10 vao list1.*/
	for (int i = 1; i <= 1500; i++)
	{
		list1.appendElement(i);
	}

	/* Nhung config voi cong cu lap.*/
	iter_list1.start(); // bat dau lap tu vi tri dau tien trong danh sach.
	for (int i = 1; i < 1000; i++)
	{
		iter_list1.advance();
	}

	/* In ra phan tu hien thoi.*/
	cout << iter_list1.current() << endl;

	/* In ra danh sach list1.*/
	printList(list1);
}

int main(int argc, char *argv[])
{
	doWithList();
	return 0;
}

