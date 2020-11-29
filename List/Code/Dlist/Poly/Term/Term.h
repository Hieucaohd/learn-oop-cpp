#pragma once
#include <iostream>
using namespace std;

class CPoly;

class CTerm
{
public:
	friend class CPoly;

	CTerm(double coef_parameter, int expo_parameter);
	/*Constructor.
	- coef: he so.
	- expo: so mu.
	*/

	CTerm();
	// Constructor rong.
	
	~CTerm();

	friend ostream & operator << (ostream &os, CTerm &t);
	// Dinh nghia phuong thuc xuat thong tin cua doi tuong Term.

	friend istream & operator >> (istream &is, CTerm &t);
	// Dinh nghia phuong thuc nhap thong tin cho doi tuong Term.
private:
	double m_coef; // he so.
	int m_expo; // so mu.
};
