#pragma once
#include <iostream>
using namespace std;

/* Khai bao truoc lop da thuc.*/
class CPoly;

class CTerm
{
public:
	friend class CPoly; // lop da thuc la lop ban.

	CTerm(double coef_parameter, int expo_parameter);
	/* Constructor
	 * coef: he so.
	 * expo: so mu.
	 * */

	CTerm();
	/* Constructor rong.
	 * */
	
	~CTerm();
	/* Destructor.
	 * */

	friend ostream & operator << (ostream &os, CTerm &t);
	/* Dinh nghia phuong thuc xuat thong tin cua doi tuong Term.
	 * */

	friend istream & operator >> (istream &is, CTerm &t);
	/* Dinh nghia phuong thuc nhap thong tin cho doi tuong Term.
	 * */
private:
	double m_coef; // he so.
	int m_expo; // so mu.
};
