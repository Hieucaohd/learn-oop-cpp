#pragma once
#include <iostream>
#include "../Nope/Nope.h"
using namespace std;

class CStack
{
private:
	CNope *m_top;
public:
	CStack();
	/* Constructor kien tao mot ngan xep rong.
	 * */

	CStack(const CStack &stack_parameter);
	/* Constructor copy.
	 * */

	~CStack();
	/* Destructor.
	 * */

	CStack operator = (const CStack &stack_parameter);
	/* Dinh nghia toan tu gan.
	 * */

	bool isStackEmpty();
	/* Postcondition: tra ve true neu ngan xep rong,
	 * tra ve false neu ngan xep khong rong.
	 * */

	void push(const typeOfData &data_parameter);
	/* Them mot phan tu vao dinh cua ngan xep.
	 * Postcondition: phan tu data_parameter tra thanh 
	 * dinh cua ngan xep.
	 * */

	typeOfData pop();
	/* Xoa phan tu o dinh cua ngan xep, dong thoi lap ra 
	 * phan tu dinh.
	 * Precondition: ham isStackEmpty() tra ve false.
	 * Postcondition: phan tu o dinh vi loai khoi ngan xep
	 * va tra ve phan tu do.
	 * */

	typeOfData  getTop();
	/* Lay ra phan tu o dinh cua ngan xep.
	 * Precondition: ham isStackEmpty() tra ve false.
	 * Postcondition: tra ve phan tu o dinh cua ngan xep.
	 * */
};

