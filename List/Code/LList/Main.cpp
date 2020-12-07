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
	cout << endl;
}

int main(int argc, char *argv[])
{
	system("clear");
	CLinkedList list1;

	/* Them cac phan tu tu 1 den 10 vao list1.*/
	for (int i = 1; i <= 10; i++)
	{
		list1.appendElement(i);
	}

	/* In ra danh sach list1.*/
	printList(list1);
	return 0;
}

