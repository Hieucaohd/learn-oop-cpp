#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Khai bao truoc lop tu dien.*/
class CDictionary;

/* Dinh nghia kieu cua trang thai ung voi moi vi tri trong mang.*/
enum stateType {ACTIVE, EMPTY, DELETED};

/* Dinh nghia kieu cua du lieu.*/
typedef int typeOfData;

/* Dinh nghia kieu cua khoa.*/
typedef int typeOfKey;

class CEntry
{
private:
public:
	typeOfData m_data;
	typeOfKey m_key;
	stateType m_state;
	friend class CDictionary; // Khai bao lop tu dien la lop ban. 

	CEntry();
	/* Constructor: rong.*/
	
	CEntry(typeOfData & data_parameter, typeOfKey & key_parameter, stateType & state_parameter);
	/* Constructor: khoi tao doi tuong bao gom day du du lieu.
	 * */

	~CEntry();
	/* Destructor.
	 * */
};

