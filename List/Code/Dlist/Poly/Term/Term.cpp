#include "Term.h"

CTerm::CTerm(double coef_parameter, int expo_parameter)
{
	m_coef = coef_parameter;
	m_expo = expo_parameter;
}

CTerm::CTerm()
{

}

CTerm::~CTerm()
{

}

ostream & operator << (ostream &os, CTerm &t)
{
	os << (double)t.m_coef << "x^" << (int)t.m_expo;
	return os;
}

istream & operator >> (istream &is, CTerm &t)
{
	cout << "Nhap he so: ";
	is >> t.m_coef;

	cout << "Nhap so mu: ";
	is >> t.m_expo;

	return is;
}
