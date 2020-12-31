#pragma once
#include <iostream>
#include <string>
#include "../Dlist/Dlist.h"

class Dset: public Dlist
{
public:
    Dset(int m);
	// Constructor: khởi tạo tập rỗng, có thể chứa nhiều nhất là m phần tử.

    bool isDsetEmpty();
	// Kiểm tra xem tập có rỗng không.

    void DsetAppend(const item &x);
	// Postcondition: phần tử x trở thành thành viên của tập động.

    void DsetDeleteElementByKey(typeOfKey k);
	// Postcondition: phần tử với khóa k không có trong tập động.

    bool searchElementByKey(typeOfKey k);
	/* 
	Postcondition: trả về true nếu tồn tại phần tử có khóa k có trong tập động 
	và false nếu không có trong tập động.
	*/

    typeOfKey maxKeyOfDset();
	/*
	Precondition: tập động không rỗng.
	Postcondition: trả về phần tử có khóa lớn nhất trong tập động.
	*/

    typeOfKey minKeyOfDset();
	/*
	Precondition: tập động không rỗng.
	Postcondition: trả về phần tử có khóa nhỏ nhất trong tập động.
	*/

	void inputDset(int numberElements);
	/* Nhap cac phan tu vao tap dong.
	 * */

	void outputDset();
	/* Postcondition: xuat ra man hinh phan tu va khoa key cua phan tu 
	 * trong tap dong.
	 * */

    void inputKeyForDset();
	/*
	Precondition: tap khong rong.
	Postcondition: key cua cac phan tu trong tap duoc nhap vao.
	*/

    void outputKeyOfDset();
	/*
	Precondition: tap khong rong.
	Postcondition: xuat ra man hinh cac phan_tu(key).
	*/

    /*
    Doi voi tap da duoc sap xep.
    Cac key duoc sap xep theo thu tu tu be den lon.
    Phan tu co key be nhat duoc xep o vi tri dau tien trong tap.
    */

    typeOfKey minKeyOfDsetSorted();
	/*
	Precondition: tap khong rong.
	Postcondition: tra ve phan tu co key be nhat trong tap.
	*/

    typeOfKey maxKeyOfDsetSorted();
	/*
	Precondition: tap khong rong.
	Postcondition: tra ve phan tu co key lon nhat trong tap.
	*/

    void DsetSortedInsert(const item &x);
	/*
	Precondition: 
	Postcondition: phan tu x duoc them vao vi tri thich hop trong tap,
	tap van trong trang thai duoc sap xep.
	*/
    
    void DsetSortedDeleteElementByKey(typeOfKey key);
	/*
	Precondition: tap khong rong.
	Postcondition: phan tu co key bi loai ra khoi tap.
	*/

    bool searchElementByKeyInDsetSorted(typeOfKey key);
	/*
	Precondition: tap khong rong;
	Postcondition: tra ve true neu tim thay phan tu,
	tra ve false neu khong tim thay phan tu.
	*/

    bool searchElementByKeyInDsetSortedUseRecursive(typeOfKey key, int bottom, int top);
}; 
