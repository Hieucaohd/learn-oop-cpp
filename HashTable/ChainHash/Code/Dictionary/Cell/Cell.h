#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Khai bao truoc lop Dictionary.*/
class CDictionary;

/* Dinh nghia kieu cua khoa.*/
typedef int typeOfKey;

/* Dinh nghia kieu cua du lieu.*/
typedef int typeOfData;

class CCell
{
private:
public:
	typeOfData m_data;
	typeOfKey m_key;
	CCell *m_next;
	friend class CDictionary; // khai bao lop ban.

	CCell();
	/* Contructor: rong.
	 * */

	CCell(const typeOfData & data_parameter, const typeOfKey & key_parameter);
	/* Constructor.
	 * */

	~CCell();
	/* Destructor.
	 * */
};

