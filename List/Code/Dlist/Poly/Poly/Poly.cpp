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
			cin >> new_term.m_expo; // nhap he so cho hang thuc.
			
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
	
}

