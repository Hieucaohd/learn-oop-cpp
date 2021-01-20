#include "HuffmanCode.h"

CPriorityQueue* frequencyOfCharater(string xau)
{
	CPriorityQueue *pri_queue = new CPriorityQueue();

	/* Khoi tao mang mang de danh dau vi tri cac ki tu giong
	 * nhau trong xau.*/
	int mang_danh_dau[xau.length()];	

	/* Cac vi tri chua bi danh dau thi ta se gan gia tri bang -1.*/
	for (int i = 0; i < xau.length(); i++)
	{
		mang_danh_dau[i] = -1;
	}

	for (int index = 0; index < xau.length(); index++)
	{
		/* Lay ki tu can dem.*/
		char ki_tu = xau[index];
		int dem = 0; // bien dem so lan ki tu xuat hien trong xau.

		for (int run = index; run < xau.length(); run++)
		{
			if (xau[run] == ki_tu && mang_danh_dau[run] == -1)
			/* Neu gap ki tu can dem va vi tri cua ki tu nay chua bi danh dau.*/
			{
			 	dem += 1;
				/* Ta se danh dau vi tri da dem bang index dau tien cua ki tu trong xau.*/
			 	mang_danh_dau[run] = index;	
			}
		}

		if (dem != 0)
		/* Neu bien dem khac 0 (tuc ki tu can dem).*/
		{
		    pri_queue->insert(xau[index], dem);
		}
	}
	return pri_queue;
}

CPriorityQueue* makeTree(string xau)
{
	CPriorityQueue *pri_queue = frequencyOfCharater(xau);

	int length_of_priQueue = pri_queue->lengthOfPriQueue();

	for (int i = 1; i <= length_of_priQueue - 1; i++)
	{
		CNope left_nope;
		CNope right_nope;
		left_nope = pri_queue->deleteMin();
		right_nope = pri_queue->deleteMin();
		CNope *left_nope_ptr = &left_nope;
		CNope *right_nope_ptr = &right_nope;

		CNope source_nope;
		source_nope.m_priority = left_nope.m_priority + right_nope.m_priority;
		copyTree(left_nope_ptr, source_nope.m_left);
		copyTree(right_nope_ptr, source_nope.m_right);

		pri_queue->insert(source_nope);
	}

	return pri_queue;
}

ostream &operator << (ostream &output, CCodeAndCharacter ma_va_ki_tu)
{
	output << ma_va_ki_tu.m_ki_tu << "(" << ma_va_ki_tu.m_ma_code << ")";
	return output;
}

bool laNopeLa(CNope *nope_ptr)
{
	if(nope_ptr->m_left == NULL && nope_ptr->m_right == NULL)
	/* Neu ca con tro trai va con tro phai deu la NULL thi no 
	 * la nope la.*/
	{
		return true;
	}
	else
	/* Neu khong thi no khong phai la nope la.*/
	{
		return false;
	}
}

bool ketThucChua(CNope *nope_ptr)
{
	if (laNopeLa(nope_ptr->m_left) && laNopeLa(nope_ptr->m_right))
	/* Neu ca cay con trai va cay con phai deu la nope la thi ta ket thuc.*/
	{
		return true;
	}
	else
	/* Neu khong thi ta chua ket thuc.*/
	{
		return false;
	}
}

void maHoaTuongUngCuaMoiKiTu(CNope *nope_ptr, CCodeAndCharacter array_ma_code[])
{
	string ma_code; // bien de luu ma hoa tuong ung cua moi ki tu.
	int dem = 0; // bien de luu cac chi so trong day array_ma_code.
	while (!ketThucChua(nope_ptr))
	{
		if (laNopeLa(nope_ptr->m_left))
		/* Neu cay con trai la nope la.*/
		{
		    ma_code.push_back('0');
			array_ma_code[dem].m_ki_tu = nope_ptr->m_left->m_data;
			array_ma_code[dem].m_ma_code = ma_code;
			dem += 1;
			ma_code.pop_back();
			ma_code.push_back('1');
			nope_ptr = nope_ptr->m_right;
		}
		else if (laNopeLa(nope_ptr->m_right))
		/* Neu cay con phai la nope la.*/
		{
		    ma_code.push_back('1');
			array_ma_code[dem].m_ki_tu = nope_ptr->m_right->m_data;
			array_ma_code[dem].m_ma_code = ma_code;
			dem += 1;
			ma_code.pop_back();
			ma_code.push_back('0');
			nope_ptr = nope_ptr->m_left;
		}
	} // End while.

	/* In ra cay con trai cua nope gan cuoi.*/
	ma_code.push_back('0');
	array_ma_code[dem].m_ki_tu = nope_ptr->m_left->m_data;
	array_ma_code[dem].m_ma_code = ma_code;
	dem += 1;
	ma_code.pop_back();

	/* In ra cay con phai cua nope gan cuoi.*/
	ma_code.push_back('1');
	array_ma_code[dem].m_ki_tu = nope_ptr->m_right->m_data;
	array_ma_code[dem].m_ma_code = ma_code;
}

string timMaTrongDay(const char &ki_tu, const CCodeAndCharacter array_ma_code[], const int &so_luong_phan_tu)
{
	for (int i = 0; i < so_luong_phan_tu; i++)
	{
		if (ki_tu == array_ma_code[i].m_ki_tu)
		{
		 	return array_ma_code[i].m_ma_code;   
		}
	}
}

string maHoaXau(const string &xau)
{
	string ma_huff_cua_xau; // bien luu lai ma huff cua xau.

	/* Tao ra cay nhi phan chua cac dinh la la cac ki tu va ma hoa tuong ung cua chung.*/
	CPriorityQueue *pri_queue = makeTree(xau);
	CNope take_nope;
	take_nope = pri_queue->deleteMin();
	CNope *nope_ptr = &take_nope;
	
	/* Khoi tao mang de luu cac ki tu va ma hoa tuong ung cua chung.*/
	int so_luong_phan_tu = frequencyOfCharater(xau)->lengthOfPriQueue();
	CCodeAndCharacter array_ma_code[so_luong_phan_tu];

	/* Luu cac ki tu va ma hoa tuong ung cua chung vao mang array_ma_code.*/
	maHoaTuongUngCuaMoiKiTu(nope_ptr, array_ma_code);

	/* Lap het cac ki tu trong xau va lay ra ma hoa tuong ung cua moi ki tu.*/
	for (int i = 0; i < xau.length(); i++)
	{
		ma_huff_cua_xau += timMaTrongDay(xau[i], array_ma_code, so_luong_phan_tu);
	}

	return ma_huff_cua_xau;
}
