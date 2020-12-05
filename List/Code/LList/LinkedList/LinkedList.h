#pragma once
#include <iostream>
#include "../Nope/Nope.h"
using namespace std;

/* Khai bao truoc cong cu lap.*/
class CListIterator;

class CLinkedList
{
private:
	int m_length; // do dai cua danh sach.
	CNope *m_head; // con tro dau.
public:
	friend class CListIterator;
	/* Khai bao cong cu lap.*/

	CLinkedList();
	/* Khoi tao mot danh sach rong.
	 * */

	CLinkedList (const CLinkedList &L);
	/* Constructor copy.
	 * */
		
	~CLinkedList();
	/* Destructor.
	 * */

	CLinkedList operator = (const CLinkedList &L);
	/* Dinh nghia toan tu gan.
	 * */

	bool isListEmpty();
	/* Postcondition: tra ve true neu danh sach rong 
	 * va false neu danh sach khong rong.
	 * */

	int length();
	/* Postcondition: tra ve so luong phan tu trong danh sach.
	 * */

	void insertElement(const typeOfData &data_parameter, int position);
	/* Chen phan tu data_parameter vao vi tri position 
	 * trong danh sach.
	 * Precondition: 1 <= position <= m_length.
	 * Postcondition: phan tu moi duoc chen vao vi tri position.
	 * */

	void appendElement(const typeOfData &data_parameter);
	/* Xen phan tu vao duoi danh sach.
	 * */
	
	void deleteElement(int position);
	/* Loai phan tu o vi tri postion trong danh sach.
	 * Precondition: 1 <= position <= m_length.
	 * Postcondition: phan tu o vi tri position 
	 * bi loai khoi danh sach.
	 * */
		
	typeOfData findElement(int postion);
	/* Tim phan tu o vi tri position trong danh sach.
	 * Precondition: 1 <= position <= m_length.
	 * Postcondition: tra ve phan tu o vi tri position 
	 * trong danh sach.
	 * */
};

