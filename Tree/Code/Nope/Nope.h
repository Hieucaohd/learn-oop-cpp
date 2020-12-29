#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef string typeOfData;
class CNope
{
private:
public:
	typeOfData m_data;
	CNope *m_first_child;
	CNope *m_next_sibling;
	CNope(typeOfData & data_parameter);
	/* Constructor.
	 * */

	~CNope();
	/* Destructor.
	 * */
};
