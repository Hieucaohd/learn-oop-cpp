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
public:
	CNope *m_root;

	/* Cac ham an phuc vu cho viec cai dat ham public.*/

	void makeEmpty(CNope * &root_ptr);
	/* Lam cho cay co goc tro boi root_ptr thanh rong, thu hoi cac te bao nho
	 * da cap phat cho cac dinh cua cay.
	 * */

	void insert(const typeOfData & data_parameter, const typeOfKey & key_parameter, CNope * &root_ptr, bool &is_taller);
	/* Xen du lieu moi data_parameter vao cay co goc tro boi root_ptr.
	 * */
	
	void deleteElementByKey(const typeOfKey & key, CNope * &root_ptr, bool &is_shorter);
	/* Loai du lieu co khoa key khoi cay co goc tro boi root_ptr.
	 * */
	
	void deleteMin(CNope * &root_ptr, CNope * &take_nope_min, bool &is_shorter);
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

	void rightRotation(CNope * &root_ptr);
	/* Quay phai cay co goc la root_ptr.
	 * */

	void leftRotation(CNope * &root_ptr);
	/* Quay trai cay co goc la root_ptr.
	 * */
	
	void leftRotationLeftChildThenRightRotationRoot(CNope * &root_ptr);
	/* Quay kep trai - phai cay co goc la root_ptr.
	 * Tuc la quay trai cay con trai cua root_ptr va
	 * sau do quay phai root_ptr.
	 * ( Khi cay bi lech trong trai, tuc la root_ptr dang bi 
	 * lech trai, va cay con trai cua root_ptr dang trong trang thai
	 * RH )
	 * */
	
	void rightRotationRightChildThenLeftRotationRoot(CNope * &root_ptr);
	/* Quay kep phai - trai cay co goc la root_ptr.
	 * Tuc la quay phai cay con phai cua root_ptr va
	 * sau do quay trai root_ptr.
	 * ( Khi cay bi lech trong phai, tuc la root_ptr dang bi 
	 * lech phai, va cay con phai cua root_ptr dang trong trang thai
	 * LH )
	 * */

	void rotationWhenLeftChildHigherAfterInsert(CNope * &root_ptr);
	/* Co 2 trang thai:
	 * TH1: root_ptr o LH va root_ptr->left o LH (lech han trai) 
	 * thi ta thuc hien phep xoay phai.
	 * TH2: root_ptr o LH va root_ptr->left o RH (lech trong trai)
	 * thi ta thuc hien phep xoay trai-phai.
	 * */

	void rotationWhenRightChildHigherAfterInsert(CNope * &root_ptr);
	/* Co 2 trang thai:
	 * TH1: root_ptr o RH va root_ptr->right o RH (lech han phai) 
	 * thi ta thuc hien phep xoay trai.
	 * TH2: root_ptr o RH va root_ptr->right o LH (lech trong phai)
	 * thi ta thuc hien phep xoay phai-trai.
	 * */

	void rotationWhenRightChildShorterAfterDelete(CNope * &root_ptr, bool &is_shorter);
	/* Xac dinh lai trang thai can bang cho dinh root_ptr khi 
	 * loai mot dinh o cay con phai cua dinh root_ptr, va phep loai lam
	 * do cao cua cay con phai ngan di 1.
	 * Bien is_shorter nhan gia tri true neu cay root_ptr ngan di 1 va false
	 * neu do cao cua cay root_ptr khong doi.
	 * */

	void rotationWhenLeftChildShorterAfterDelete(CNope * &root_ptr, bool &is_shorter);
	/* Xac dinh lai trang thai can bang cho dinh root_ptr khi 
	 * loai mot dinh o cay con trai cua dinh root_ptr, va phep loai lam
	 * do cao cua cay con trai ngan di 1.
	 * Bien is_shorter nhan gia tri true neu cay root_ptr ngan di 1 va false
	 * neu do cao cua cay root_ptr khong doi.
	 * */

	void delNope(CNope * &node_need_del, bool &is_shorter);
	/* Xoa bo dinh node_need_del trong cay.
	 * */
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
