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
	/* Sao chep cac dinh tu cay from_root_ptr sang cay to_root_ptr.
	 * */







	~CDynamicSet();
	/* Destructor.
	 * */

	void makeEmpty(CNope * &root_ptr);
	/* Lam cho cay co goc tro boi root_ptr thanh rong, thu hoi cac te bao nho
	 * da cap phat cho cac dinh cua cay.
	 * */






	void deleteElementByKey(const typeOfKey & key, CNope * &root_ptr, typeOfData &take_data);
	/* Loai du lieu co khoa key khoi cay co goc tro boi root_ptr.
	 * Du lieu tu khoa bi xoa duoc luu vao bien take_data.
	 * */

	typeOfData deleteElementByKey(const typeOfKey & key);
	/* Xoa du lieu co khoa la key.
	 * */





	void insert(const typeOfData & data_parameter, const typeOfKey & key_parameter, CNope * &root_ptr, string &way);
	/* Xen du lieu moi data_parameter vao cay co goc tro boi root_ptr.
	 * Bien way luu lai duong di de xac dinh kieu zig va zag trong qua trinh loe cay tu dinh moi
	 * them vao len den goc cay.
	 * */

	void insert(const typeOfData & data_parameter, const typeOfKey & key_parameter);
	/* Xem du lieu moi vao tap.
	 * */

	



	void search(const typeOfKey & key, typeOfData &take_data, CNope * &root_ptr, string &way, bool &is_found);
	/* Tim kiem du lieu co khoa la key trong cay co goc tro boi root_ptr.
	 * Neu tim thay thi luu du lieu vao bien take_data va is_fould nhan gia tri tru.
	 * Neu khong tim thay thi is_found nhan gia tri false.
	 * Bien way luu lai duong di de xac dinh kieu zig va zag trong qua trinh loe cay tu dinh can tim 
	 * len den goc cay.
	 * */

	bool search(const typeOfKey & key, typeOfData &take_data);
	/* Tim du lieu co khoa la key, bien take_data luu lai du lieu do.
	 * Precondition: tap khong rong.
	 * Postcondition: tra ve true neu ton tai du lieu co khoa key trong tap,
	 * tra ve false neu khong.
	 * */





	void min(CNope * &root_ptr, CNope &take_nope, string &way, const CNope * initial_nope_ptr);
	/* Tra ve du lieu co khoa nho nhat tren cay co goc tro boi root_ptr.
	 * Bien way va bien initial_nope_ptr phuc vu cho qua trinh loe cay.
	 * Bien take_nope luu lai du lieu tu dinh co khoa nho nhat trong cay.
	 * */

	CNope min();
	/* Precondition: cay khong rong.
	 * Postcondition: tra ve du lieu co khoa nho nhat trong tap.
	 * */





	void max(CNope * &root_ptr, CNope &take_nope, string &way, const CNope * initial_nope_ptr);
	/* Tra ve du lieu co khoa nho nhat tren cay co goc tro boi root_ptr.
	 * Bien way va bien initial_nope_ptr phuc vu cho qua trinh loe cay.
	 * Bien take_nope luu lai du lieu tu dinh co khoa nho nhat trong cay.
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
