#pragma once
#include <iostream>
#include "../LinkedList/LinkedList.h"
#include "../Nope/Nope.h"
using namespace std;

class CListIterator
{
private:
	CNope *m_current;
	CLinkedList *m_List_ptr;
public:
	CListIterator(CLinkedList &L);
	/* Constructor kien tao.*/

	~CListIterator();
	/* Destructor.*/
	
	void start();
	/* Postcondition: vi tri hien thoi la vi tri
	 * dau tien trong danh sach.
	 * */

	void advance();
	/* Postcondition: vi tri hien thoi la vi tri 
	 * tiep theo trong danh sach, neu vi tri hien thoi 
	 * dang o cuoi danh sach thi vi tri tiep theo se la
	 * vi tri dau tien trong danh sach.
	 * */

	bool valid();
	/* Postcondition: tra ve true neu vi tri hien thoi 
	 * trong danh sach va tra ve false neu khong.
	 * */
	
	typeOfData current();
	/* Precondition: ham valid() tra ve true.
	 * Postcondition: tra ve phan tu hien thoi 
	 * trong danh sach.
	 * */
	
	void add(const CNope &data_parameter);
	/* Them phan tu vao vi tri hien thoi.
	 * Precondition: ham valid() tra ve true.
	 * Postcondition: nope_parameter duoc them vao vi tri
	 * hien thoi, phan tu hien thoi van la phan tu hien thoi.
	 * */
	
	void remove();
	/* Precondition: ham valid() tra ve true.
	 * Postcondition: phan tu hien thoi vi loai ra khoi danh sach,
	 * phan tu di sau no tro thanh phan tu hien thoi.
	 * */
};


