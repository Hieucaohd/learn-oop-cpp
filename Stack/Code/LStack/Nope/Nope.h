#pragma once
#include <iostream>
using namespace std;

// xac dinh kieu cua typeOfData.
typedef string typeOfData; 

/* Khai bao truoc lop ngan xep.*/
class CStack;

class CNope
{
private:
	typeOfData m_data; // phan du lieu.
	CNope *m_next; 
public:
	friend class CStack;
	/* Khia bao lop ngan xep la ban.
	 * */

	CNope(const typeOfData &data_parameter);
	/* Constructor.
	 * */

	~CNope();
	/* Destructor.
	 * */
};

