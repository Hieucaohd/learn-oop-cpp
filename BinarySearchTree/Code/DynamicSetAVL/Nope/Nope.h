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

/* LH: left high.
 * EH: equal high.
 * RH: right hight.
 * Duoc goi la trang thai can bang.
 * */
enum stateType {LH, EH, RH};

class CNope
{
public:
	stateType m_balance;
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
