#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Nope/Nope.h"

using namespace std;

/* Lop tap dong duoc cai dat boi CTDL cay tim kiem nhi phan.*/
class CDynamicSet
{
private:
	CNope *m_root;

	/* Cac ham an phuc vu cho viec cai dat ham public.*/

	void makeEmpty(CNope * &root_ptr);
	/* Lam cho cay co goc tro boi root_ptr thanh rong, thu hoi cac te bao nho
	 * da cap phat cho cac dinh cua cay.
	 * */

	void insert(const typeOfData & data_parameter, const typeOfKey & key_parameter, CNope * &root_ptr);
	/* Xen du lieu moi data_parameter vao cay co goc tro boi root_ptr.
	 * */
	
	void deleteElementByKey(const typeOfKey & key, CNope * &root_ptr);
	/* Loai du lieu co khoa key khoi cay co goc tro boi root_ptr.
	 * */
	
	CNope * deleteMin(CNope * &root_ptr);
	/* Loai du lieu co khoa nho nhat khoi cay co goc tro boi root_ptr.
	 * */

	bool search(const typeOfKey & key, typeOfData &take_data, CNope * &root_ptr);
	/* Tim kiem du lieu co khoa la key trong cay co goc tro boi root_ptr.
	 * */
	
	typeOfData min(CNope * &root_ptr);
	/* Tra ve du lieu co khoa nho nhat tren cay co goc tro boi root_ptr.
	 * */

	typeOfData max(CNope * &root_ptr);
	/* Tra ve du lieu co khoa lon nhat tren cay co goc tro boi root_ptr.
	 * */

public:
	CDynamicSet();
	/* Constructor: khoi tao mot tap rong.
	 * */

	CDynamicSet(const CDynamicSet & set);
	/* Constructor copy.
	 * */

	 CDynamicSet(const CDynamicSet * set_ptr);
	/* Constructor copy cua con tro.
	 * */

	CDynamicSet operator = (const CDynamicSet &set);
	/* Dinh nghia toan tu gan.
	 * */

	friend void copyTree(const CNope * from_root_ptr, CNope * &to_root_ptr);

	~CDynamicSet();
	/* Destructor.
	 * */
	
	bool isSetEmpty();
	/* Kiem tra xem tap co rong khong.
	 * Postcondition: tra ve true neu tap rong,
	 * tra ve false neu tap khong rong.
	 * */

	void insert(const typeOfData & data_parameter, const typeOfKey & key_parameter);
	/* Xem du lieu moi vao tap.
	 * */

	void deleteElementByKey(const typeOfKey & key);
	/* Xoa du lieu co khoa la key.
	 * */

	CNope * deleteMin();
	/* Loai du lieu co khoa nho nhat, dong thoi tra ve du lieu nay.
	 * Precondition: tap khong rong.
	 * Postcondition: du lieu co khoa nho nhat bi loai ra khoi tap,
	 * tra ve du lieu co khoa nho nhat.
	 * */

	bool search(const typeOfKey & key, typeOfData &take_data);
	/* Tim du lieu co khoa la key, bien take_data luu lai du lieu do.
	 * Precondition: tap khong rong.
	 * Postcondition: tra ve true neu ton tai du lieu co khoa key trong tap,
	 * tra ve false neu khong.
	 * */

	typeOfData min();
	/* Precondition: cay khong rong.
	 * Postcondition: tra ve du lieu co khoa nho nhat trong tap.
	 * */

	typeOfData max();
	/* Precondition: cay khong rong.
	 * Postcondition: tra ve du lieu co khoa lon nhat trong tap.
	 * */

};
