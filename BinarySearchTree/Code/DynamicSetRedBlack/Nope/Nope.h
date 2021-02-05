#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Khai bao truoc lop CDynamicSet.*/
class CDynamicSet;

/* Dinh nghia kieu cua du lieu va kieu cua khoa.*/
typedef int typeOfData;
typedef int typeOfKey;

class CNope
{
private:
public:
	typeOfData m_data;
	typeOfKey m_key;
	CNope *m_left;
	CNope *m_right;
	friend class CDynamicSet; // Khai bao lop ban.

	CNope(const typeOfData & data_parameter, const typeOfKey & key_parameter);
	/* Constructor.
	 * */

	~CNope();
	/* Destructor.
	 * */
};

