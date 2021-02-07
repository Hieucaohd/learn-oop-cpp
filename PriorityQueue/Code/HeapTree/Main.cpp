#include <iostream>
#include <string>
#include <vector>

#include "PriorityQueue/PriorityQueue.h"
#include "Nope/Nope.h"
#include "HuffmanCode/HuffmanCode.h"
#include "Stack/Stack.h"

using namespace std;

void thu1()
{
	string xau = "aeehhhh";
	CPriorityQueue *pri_queue = frequencyOfCharater(xau);
	int length_of_priQueue = pri_queue->lengthOfPriQueue();

	for (int i = 1; i <= length_of_priQueue; i++)
	{
		cout << pri_queue->deleteMin() << endl;
	}
}

void thu2()
{
	string xau = "aeehhhh";
	string ma_huff_cua_xau = maHoaXau(xau);

	/* Tao ra cay nhi phan chua cac dinh la la cac ki tu va ma hoa tuong ung cua chung.*/
	CPriorityQueue *pri_queue = makeTree(xau);
	CNope take_nope;
	take_nope = pri_queue->deleteMin();
	CNope *nope_ptr = &take_nope;

	string ma_giai;
	CNope *run_ptr = nope_ptr;

	for (int i = 0; i < ma_huff_cua_xau.length(); i++)
	{
		
		if (run_ptr->m_left == NULL && run_ptr->m_right == NULL)
		{
			ma_giai.push_back(run_ptr->m_data);
			run_ptr = nope_ptr;
		}

		if (ma_huff_cua_xau[i] == '0')
		{
			run_ptr = run_ptr->m_left;
		}
		else 
		{
			run_ptr = run_ptr->m_right;
		}
	}

	cout << ma_giai << endl;
}

void thu3()
{
	string xau;
	fflush(stdin);
	getline(cin, xau);

	/* Tao ra cay nhi phan chua cac dinh la la cac ki tu va ma hoa tuong ung cua chung.*/
	CPriorityQueue *pri_queue = makeTree(xau);
	CNope take_nope;
	take_nope = pri_queue->deleteMin();
	CNope *nope_ptr = &take_nope;
	
	/* Khoi tao mang de luu cac ki tu va ma hoa tuong ung cua chung.*/
	int so_luong_phan_tu = frequencyOfCharater(xau)->lengthOfPriQueue();
	CCodeAndCharacter array_ma_code[so_luong_phan_tu];
	int dem = 0; // bien dem luu lai cac chi so cua mang.

	/* Luu cac ki tu va ma hoa tuong ung cua chung vao mang array_ma_code.*/
	CStack stack_string; // stack phuc vu viec cai dat de quy.
	string ma_code; // bien luu lai tuong ma code cua tung ki tu.
	codeOfCharacter(nope_ptr, stack_string, ma_code, array_ma_code, dem, so_luong_phan_tu);

	for (int i = 0; i < so_luong_phan_tu; i++)
	{
		cout << array_ma_code[i] << endl;
	}
}

void thu4()
{
	string xau = "aeehhhh";

	cout << maHoaXau(xau) << endl;
}

void thu5()
{
	string xau;
	fflush(stdin);
	getline(cin, xau);
	string ma_huff_cua_xau = maHoaXau(xau);
	cout << ma_huff_cua_xau << endl;

	/* Tao ra cay nhi phan chua cac dinh la la cac ki tu va ma hoa tuong ung cua chung.*/
	CPriorityQueue *pri_queue = makeTree(xau);
	CNope take_nope;
	take_nope = pri_queue->deleteMin();
	CNope *nope_ptr = &take_nope;

	cout << giaiMaXau(ma_huff_cua_xau, nope_ptr) << endl;
}

int main(int argc, char *argv[])
{
	thu5();
	return 0;
}
