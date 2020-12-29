#pragma once
#include <iostream>
#include "../Term/Term.h"
#include "../Dlist/Dlist.h"
#include "../DlistIterator/DlistIterator.h"
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
	/* Destructor.
	 * */

	void inputPoly(int number_Terms);
	/* Phuong thuc nhap da thuc.
	 * number_Terms: bac cua da thuc.
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
