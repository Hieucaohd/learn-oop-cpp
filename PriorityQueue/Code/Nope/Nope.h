#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Khai bao truoc lop PriorityQueue.*/
class CPriorityQueue;

/* Dinh nghia kieu cua du lieu vao kieu cua muc uu tien.*/
typedef int typeOfData;
typedef int typeOfPriority;

class CNope
{
private:
	typeOfData m_data; // bien luu lai du lieu cua phan tu.
	typeOfPriority m_priority; // bien luu lai gia tri uu tien cua phan tu.
	CNope *m_left;
	CNope *m_right;
public:
	friend class CPriorityQueue; // khai bao lop ban.

	CNope();
	/* Constructor rong.
	 * */

	CNope(const typeOfData &data_parameter, const typeOfPriority &priority_parameter);
	/* Constructor.
	 * */

	~CNope();
	/* Destructor.
	 * */

	void operator = (const CNope &nope_parameter);
	/* Dinh nghia toan tu gan.
	 * */
};
