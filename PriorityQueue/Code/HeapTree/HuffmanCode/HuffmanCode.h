#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../PriorityQueue/PriorityQueue.h"
#include "../Stack/Stack.h"

struct CCodeAndCharacter
{
	char m_ki_tu;
	string m_ma_code;
};

CPriorityQueue* frequencyOfCharater(string xau);
/* Tao ra mot hang uu tien luu tan xuat cac ki tu trong xau.
 * */

CPriorityQueue* makeTree(string xau);
/* Tao ra cay nhi phan chua cac dinh la cac ki tu cung voi so lan 
 * xuat hien cua chung trong xau.
 * */

ostream &operator << (ostream &output, CCodeAndCharacter ma_va_ki_tu);
/* Dinh nghia toan tu in ra ki tu va ma code tuong ung cua no.
 * */

bool laNopeLa(CNope *nope_ptr);
/* Kiem tra xem nope_ptr co phai la nope la hay khong.
 * */

bool ketThucChua(CNope *nope_ptr);
/* Kiem tra xem 2 cay con trai va phai cua nope_ptr co phai la nope la hay khong.
 * Neu dung thi tra ve true.
 * Neu sai thi tra ve false.
 * */

void maHoaTuongUngCuaMoiKiTu(CNope *nope_ptr, CCodeAndCharacter array_ma_code[]);
/* Ham luu ki tu va ma code cua no trong mang array_ma_code[].
 * Ta loi dung ket qua sau:
 * 		- O moi muc cua cay nhi phan ta se co mot la va mot cay khong phai la la.
 * 		- Dinh la la la dinh can lay.
 * */

void codeOfCharacter(CNope *nope_ptr, CStack &stack_string, string &ma_hoa, CCodeAndCharacter array_ma_code[], int &dem, const int &so_luong_phan_tu);
/* Ma hoa tuong ung cua moi ki tu.
 * */

string timMaTrongDay(const char &ki_tu, const CCodeAndCharacter array_ma_code[], const int &so_luong_phan_tu);
/* Ham tim dang ma hoa cua ki tu trong day chua cac ki tu va ma hoa cua no.
 * */

string maHoaXau(const string &xau);
/* Tra ve dang ma hoa cua xau.
 * */

string giaiMaXau(const string ma_huff_cua_xau, CNope *nope_ptr);
/* Tra ve xau ban dau tu ma hoa huff.
 * */
