#include "Poly.h"

CPoly::CPoly()
{
	
}

CPoly::~CPoly()
{

}

void CPoly::inputPoly(int number_Terms)
{
	if (number_Terms > 0)
	/* So hang thuc can nhap phai lon hon 0.*/
	{
		for (int i = 1; i <= number_Terms; i++)
		{
			CTerm new_term; // tao mot hang thuc.
			new_term.m_expo = i - 1; // gan so mu cho hang thuc.

			cout << "Nhap he so cua x^" << i - 1 << ": ";
			cin >> new_term.m_coef; // nhap he so cho hang thuc.
			
			/* Them hang thuc vao cuoi danh sach da thuc.*/
			m_Term_list.append(new_term);
		}
	}
	else
	/* So hang thuc can nhap khong hop le.*/
	{
		cout << "So hang thuc can nhap khong hop le." << endl;
	}
}

void CPoly::outputPoly()
{
	if (m_Term_list.length() != 0)
	/* Da thuc khac 0.*/
	{
		for (int i = m_Term_list.length(); i >= 2; i--)
		{
			CTerm output_Term = m_Term_list.findElement(i);
			cout << output_Term << " + ";
		}

		/* In ra phan tu cuoi cung cho dep.*/
		CTerm output_Term_last = m_Term_list.findElement(1);
		cout << output_Term_last << endl; 
	}
	else
	/* Da thuc bang 0.*/
	{
		cout << "0" << endl;
	}
}

CPoly CPoly::operator + (const CPoly &poly_parameter)
{
	CTerm term1, term2, term_result;
	/* term1 <-> poly.
	 * term2 <-> poly_parameter.
	 * term_result <-> poly_result.
	 * */
	
	CPoly poly_result; // poly_result = poly_parameter + poly.
	
	// Khai bao 2 iterator de lap qua 2 da thuc.
	CDlistIterator itr1(m_Term_list);
	CDlist Dlist_poly_parameter = poly_parameter.m_Term_list;
	CDlistIterator itr2(Dlist_poly_parameter);

	itr1.start();
	itr2.start();
	
	while (itr1.valid() && itr2.valid())
	/* Duyet lan luot qua cac phan tu cua 2 da thuc.*/
	{
		term1 = itr1.current();
		term2 = itr2.current();	

		if (term1.m_expo == term2.m_expo)
		/* Neu 2 so mu bang nhau.*/
		{
			if (term1.m_coef + term2.m_coef != 0)
			/* Neu tong he so khac 0.*/
			{
				/* Khoi tao hang thuc term_result.*/
			 	term_result.m_coef = term1.m_coef + term2.m_coef;   
				term_result.m_expo = term1.m_expo;

				poly_result.m_Term_list.append(term_result);
				/* Them hang thuc term_result vao duoi cua
				 * da thuc ket qua.
				 * */
			}
			
			itr1.advance();
			itr2.advance();
		}
		else if (term1.m_expo > term2.m_expo)
		/* Neu so mu cua term1 > term2.*/
		{
			/* Thi term_result = term1.*/
			poly_result.m_Term_list.append(term1);
		}
		else
		/* Neu so mu cua term2 > term1.*/
		{
			/* Thi term_result = term2.*/
			poly_result.m_Term_list.append(term2);
		}
	} // End while.

	while (itr1.valid())
	/* Neu da thuc poly van con hang tu.*/
	{
		term1 = itr1.current();
		poly_result.m_Term_list.append(term1);
		itr1.advance();
	}

	while (itr2.valid())
	/* Neu da thuc poly_parameter van con hang tu.*/
	{
		term2 = itr2.current();
		poly_result.m_Term_list.append(term2);
		itr2.advance();
	}
	
	return poly_result;
}

