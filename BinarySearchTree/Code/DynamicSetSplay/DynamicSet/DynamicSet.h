#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "../Nope/Nope.h"
#include "/home/hieu/CodeTemplate/Stack/Stack.cpp"

using namespace std;

/* Lop tap dong duoc cai dat boi CTDL cay tim kiem nhi phan.*/
class CDynamicSet
{
private:
public:
	CNope *m_root;


	


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

	void makeEmpty(CNope * &root_ptr);
	/* Lam cho cay co goc tro boi root_ptr thanh rong, thu hoi cac te bao nho
	 * da cap phat cho cac dinh cua cay.
	 * */






	void deleteElementByKey(const typeOfKey & key, CNope * &root_ptr, typeOfData &take_data);
	/* Loai du lieu co khoa key khoi cay co goc tro boi root_ptr.
	 * */

	typeOfData deleteElementByKey(const typeOfKey & key);
	/* Xoa du lieu co khoa la key.
	 * */





	void insert(const typeOfData & data_parameter, const typeOfKey & key_parameter, CNope * &root_ptr, string &way);
	/* Xen du lieu moi data_parameter vao cay co goc tro boi root_ptr.
	 * */

	void insert(const typeOfData & data_parameter, const typeOfKey & key_parameter);
	/* Xem du lieu moi vao tap.
	 * */

	



	void search(const typeOfKey & key, typeOfData &take_data, CNope * &root_ptr, string &way, bool &is_found);
	/* Tim kiem du lieu co khoa la key trong cay co goc tro boi root_ptr.
	 * */

	bool search(const typeOfKey & key, typeOfData &take_data);
	/* Tim du lieu co khoa la key, bien take_data luu lai du lieu do.
	 * Precondition: tap khong rong.
	 * Postcondition: tra ve true neu ton tai du lieu co khoa key trong tap,
	 * tra ve false neu khong.
	 * */





	void min(CNope * &root_ptr, CNope &take_nope, string &way, const CNope * initial_nope_ptr);
	/* Tra ve du lieu co khoa nho nhat tren cay co goc tro boi root_ptr.
	 * */

	CNope min();
	/* Precondition: cay khong rong.
	 * Postcondition: tra ve du lieu co khoa nho nhat trong tap.
	 * */





	void max(CNope * &root_ptr, CNope &take_nope, string &way, const CNope * initial_nope_ptr);
	/* Tra ve du lieu co khoa nho nhat tren cay co goc tro boi root_ptr.
	 * */

	CNope max();
	/* Precondition: cay khong rong.
	 * Postcondition: tra ve du lieu co khoa nho nhat trong tap.
	 * */







	void rightRotation(CNope * &root_ptr);
	/* Quay phai cay co goc la root_ptr.
	 * */

	void leftRotation(CNope * &root_ptr);
	/* Quay trai cay co goc la root_ptr.
	 * */





	bool isSetEmpty();
	/* Kiem tra xem tap co rong khong.
	 * Postcondition: tra ve true neu tap rong,
	 * tra ve false neu tap khong rong.
	 * */	
};
