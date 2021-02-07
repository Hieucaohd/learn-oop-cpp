#pragma once
#include <iostream>
using namespace std;

// xac dinh kieu cua typeOfDataStack.
typedef string typeOfDataStack; 

/* Khai bao truoc lop ngan xep.*/
class CStack;

class CNopeStack
{
private:
	typeOfDataStack m_data; // phan du lieu.
	CNopeStack *m_next; 
public:
	friend class CStack;
	/* Khia bao lop ngan xep la ban.
	 * */

	CNopeStack(const typeOfDataStack &data_parameter);
	/* Constructor.
	 * */

	~CNopeStack();
	/* Destructor.
	 * */
};

