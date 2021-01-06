#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Entry/Entry.h"

using namespace std;

/* Tu dien duoc cai dat bang bang bam dia chi mo.*/
class CDictionary
{
private:
public:
	const int static SIZE = 811; // Kich co cua mang.

	CDictionary();
	/* Constructor: khoi tao mot tu dien rong.
	 * */

	~CDictionary();
	/* Destructor.
	 * */

	bool search(typeOfKey & key, typeOfData & data);
	/* Tim du lieu co khoa la key.
	 * Neu tim thay thi bien data ghi lai du lieu can tim.
	 * Postcondition: tra ve true neu tim thay,
	 * va neu khong tim thay thi tra ve false.
	 * */
	
	void insert(const typeOfData &data_parameter, const typeOfKey &key_parameter, bool &is_success);
	/* Xen vao du lieu data_parameter.
	 * Postcondition: bien is_success nhan gia tri la true neu xen thanh cong,
	 * va false neu khong thanh cong.
	 * */
	
	void deleteElementByKey(typeOfKey & key);
	/* Loai khoi tu dien du lieu co khoa la key.
	 * */

	CEntry *m_array_datas; // danh sach du lieu trong bang.

	bool find(const typeOfKey & key, int & index_ACTIVE, int & index_EMPTY_DELETED);
	/* Ham thuc hien tham do du lieu co khoa key.
	 * Neu thanh cong, ham tra ve true va bien index ghi lai chi so tai do chua du lieu.
	 * Neu that bai, ham tra ve false va bien index_else ghi lai chi so dau tien ma o trang thai 
	 * EMPTY hoac DELETED neu tham do phat hien ra.
	 * */

	int probing(int & position, int & number);
	/* position la vi tri ban dau duoc xac dinh boi bam khoa key, position = h(key).
	 * Postcondition: tra ve vi tri tham do o lan bam thu number = 0, 1, 2, ...
	 * */
	
	int hash(const typeOfKey & key);
	/* Ham bam.
	 * */
};
