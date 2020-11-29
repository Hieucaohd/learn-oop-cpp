#pragma once
#include <iostream>
#include "../Term/Term.h"
using namespace std;

class CDlistIterator;
// Khai bao truoc lop CDlistIterator.

typedef CTerm typeOfElement;
// Khai bao kieu cua cac doi tuong trong danh sach.

class CDlist
{
public:
	friend class CDlistIterator;
	// Khai bao lop CDlistIterator la lop ban.

	CDlist();
	// Constructor: khoi tao mot mang rong.

	CDlist(int size_parameter);
	/*Constructor: mot mang rong cac doi tuong duoc cap phat dong.
	- Precondition: size_parameter nguyen duong.
	- Postcondition: mot danh sach rong duoc khoi tao, 
	voi kha nang chua toi da size_parameter phan tu.
	*/

	CDlist(const CDlist &L);
	// Constructor - copy.

	CDlist & operator = (const CDlist &L);
	// Định nghĩa toán tử "=" để copy từ đối tượng L.

	~CDlist();
	// Dis-constructor: thu hoi bo nho duoc cap phat dong cho mang m_elements.

	void inputDlist(int numberElements);
	/*Nhap cac phan tu cho danh sach.
	- Neu so phan tu can nhap lon hon kich thuoc hien tai cua mang
	thi ta cap phat mang moi co kich thuoc x2 mang cu.
	*/

	void outputDlist();
	/*In ra man hinh cac phan tu cua danh sach.
	- Precondition: danh sach khong rong.
	- Postcondition: xuat ra man hinh danh sach.
	*/

	bool isDlistEmpty() 
	{
		/*Kiem tra xem danh sach co rong khong.
		- Postcondition: tra ve true neu danh sach rong va false neu khong.
		*/
		return (length() == 0);
	}

	int length() const
	{
		/*Xac dinh do dai cua danh sach.
		- Postcondition: tra ve so luong phan tu trong danh sach.
		*/
		return m_last + 1;
	}

	void insert(const typeOfElement &element_parameter, int position_insert);
	/*Them mot phan tu vao mot vi tri trong danh sach. 
	- LƯU Ý: phần tử thứ i của danh sách (i = 1, 2, 3,...) 
	được lưu trong thành phần m_elements[i - 1] của mảng m_elements.
	- Xen phần tử element_parameter vào vị trí thứ position_insert trong danh sách. 
	Nếu length() >= m_size thì ta sẽ cấp phát động một mảng mới có kích cỡ gấp đôi mảng cũ.
	- Precondition: 1 <= position_insert <= length().
	- Postcondition: các phần tử của danh sách kể từ vị trí thứ position_insert được đẩy ra sau 
	một vị trí, phần tử x nằm ở vị trí thứ position_insert.
	*/	

	void append(const typeOfElement &element_parameter);
	/*Thêm phần tử element_parameter vào đuôi danh sách.
	- Nếu length() >= m_size thì ta sẽ cấp phát động một mảng mới có kích thước gấp đôi mảng cũ.
	- Postcondition: element_parameter là phần tử ở đuôi của danh sách.
	*/	

	void deleteElement(int position);
	/*Loại khỏi danh sách phần tử ở vị trí position.
	- Precondition: 1 <= i <= length().
	- Postcondition: phần tử ở vị trí thứ position bị loại khỏi danh sách, 
	các phần tử từ vị trí thứ position + 1 được lùi về sau 1 vị trí.
	*/

	typeOfElement findElement(int position);
	/*Tìm phần tử ở vị trí thứ i.
	- Precondition: 1 <= i <= length().
	- Postcondition: trả về phần tử ở vị trí i.
	*/
private:
	typeOfElement *m_elements;
	int m_size; // kích cỡ của mảng cấp phát động m_elements[]. 
	int m_last; // số lượng phần tử có trong danh sách length() =  m_last + 1.
};
