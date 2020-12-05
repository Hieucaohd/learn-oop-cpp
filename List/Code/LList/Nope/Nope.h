#pragma once
#include <iostream>
using namespace std;

/* Khai bao truoc lop CLinkedList.*/
class CLinkedList;

/* Khai bao truoc cong cu lap.*/
class CListIterator;

typedef int typeOfData; // xac dinh kieu cua typeOfData.
class CNope
{
private:
	typeOfData m_data; // phan du lieu.
	CNope *m_next; 
	CNope *m_precede;
public:
	friend class CLinkedList;
	/* Khai bao lop CLinkedList la lop ban.
	 * */

	friend class CListIterator;
	/* Khai bao cung cu lap la lop ban.
	 * */

	CNope(const typeOfData &data_parameter);
	/* Constructor.
	 * */

	~CNope();
	/* Destructor.
	 * */
};

