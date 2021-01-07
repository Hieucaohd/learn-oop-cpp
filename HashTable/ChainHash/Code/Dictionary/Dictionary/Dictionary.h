#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Cell/Cell.h"

using namespace std;

class CDictionary
{
private:
public:
	void hieu();
	const int static SIZE = 811; // kich co cua mang.

	CDictionary();
	/* Constructor: rong.
	 * */

	CDictionary(const CDictionary &dic);
	/* Constructor copy.
	 * */

	void operator = (const CDictionary &dic);
	/* Dinh nghia toan tu gan.
	 * */

	~CDictionary();
	/* Destructor.
	 * */

	/* Cac phep toan tu dien: */

	bool search(const typeOfKey & key, typeOfData & take_data);
	/* Tim kiem du lieu co khoa la key.
	 * Luu du lieu vao bien data.
	 * Postcondition: tra ve true neu tim thay,
	 * va tra ve false neu khong tim thay.
	 * */

	void insert(const typeOfData & data_parameter, const typeOfKey & key_parameter, bool & is_success);
	/* Them du lieu data_parameter voi khoa key_parameter vao tu dien.
	 * Neu them thanh cong thi gan bien is_success gia tri la true,
	 * neu them khong thanh cong thi gan bien is_success gia tri la false.
	 * */
	
	void deleteElementByKey(const typeOfKey & key);
	/* Xoa du lieu co khoa la key trong tu dien.
	 * */

	CCell *m_array_datas[SIZE]; // mang chua du lieu.

	int hash(const typeOfKey & key);
	/* Ham bam.
	 * */
};
