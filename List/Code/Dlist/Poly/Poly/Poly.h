#pragma once
#include <iostream>
#include "../Term/Term.h"
#include "../Dlist/Dlist.h"
using namespace std;

class CPoly
{
private:
	CDlist m_Term_list; // danh sach cac hang thuc.
public:
	CPoly();
	/* Constructor khoi tao.
	 * */

	~CPoly();
	/* Constructor huy.
	 * */

	void inputPoly(int number_Terms);
	/* Phuong thuc nhap da thuc.
	 * Precondition: number_Terms nguyen duong.
	 * */

	void outputPoly();
	/* Phuong thuc xuat da thuc.
	 * Postcondition: xuat ra man hinh da thuc.
	 * */

	CPoly operator + (const CPoly &poly_parameter);
	/* Dinh nghia phep toan cong 2 da thuc.
	 * */
};
