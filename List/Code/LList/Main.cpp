#include <iostream>
#include "LinkedList/LinkedList.h"
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
	list1.appendElement(1);
	list1.appendElement(2);

	/* In ra do dai cua danh sach list1.*/
	cout << "Do dai cua danh sach la: " << list1.length() << endl;

	CLinkedList list2;
	list2 = list1;
	cout << "Do dai cua danh sach la: " << list2.length() << endl;
	
	printList(list2);

	return 0;
}

