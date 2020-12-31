#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef string typeOfItem;
typedef int typeOfKey;

struct item
{
	typeOfKey key;
	typeOfItem data;
};

// Khai bao truoc lop cong cu lap.
class DlistIterator;

// Lop danh sach duoc cai dat boi mang dong.
// Dlist = Dynamic List: danh sách cấp phát động
class Dlist
{
private:
	item *elements;
	int size; // kích cỡ của mảng cấp phát động elements[]. 
	int last; // số lượng phần tử có trong danh sách length() =  last + 1.
public:
	friend class DlistIterator; // công cụ iterator làm hàm bạn

	Dlist();
	// Constructor: khởi tạo một mảng rỗng

	Dlist(int m);
	/* 
	Constructor: khởi tạo cỡ của mảng được cấp phát động 
	với m = cỡ của mảng được cấp phát động
	Precondition: m nguyên dương
	Postcondition: một danh sách rỗng được khởi tạo với khả năng tối đa chứa m phần tử
	*/

	Dlist(const Dlist &L);
	// Constructor - copy.

	Dlist & operator = (const Dlist &L);
	// Định nghĩa toán tử "=" để copy từ đối tượng L.

	~Dlist();
	// Destructor: thu hồi bộ nhớ được cấp phát động cho mảng elements.

	void inputElementsOfDlist(int numberElements);
	/*
	Nhập các phần tử cho danh sách.
	Nếu số phần tử cần nhập lớn hơn kích thước của danh sách 
	thì ta cấp phát một mảng mới có kích thước gấp đôi mảng cũ.
	*/

	void outputElementsOfDlist();
	/*
	Xuat ra cac phan tu trong danh sach. 
	Postcondition: in ra man hinh cac phan tu trong danh sach.
	*/

	void setKeyOfElement(const typeOfKey &key, const int &i);
	/*
	Them khoa key cho cac phan tu trong danh sach. 
	*/

	bool isDlistEmpty() const;
	/* 
	Kiểm tra xem một danh sách có rỗng không.
	Postcondition: trả về true nếu danh sách rỗng và false nếu không.
	*/

	int length() const;
	/* 
	Xác định độ dài của danh sách.
	Postcondition: trả về số phần tử trong danh sách.
	*/

	void insert(const item &x, int i);
	/* 
	LƯU Ý: phần tử thứ i của danh sách (i = 1, 2, 3,...) được lưu trong thành phần elements[i - 1] của mảng động.
	Xen phần tử x vào vị trí thứ i trong danh sách. 
	Nếu length() >= size thì ta sẽ cấp phát động một mảng mới có kích cỡ gấp đôi mảng cũ.
	Precondition: 1 <= i <= length().
	Postcondition: các phần tử của danh sách kể từ vị trí thứ i được đẩy ra sau một vị trí, phần tử x nằm ở vị trí thứ i.
	*/

	void append(const item &x);
	/* 
	Thêm phần tử x vào đuôi danh sách.
	Nếu length() >= size thì ta sẽ cấp phát động một mảng mới có kích thước gấp đôi mảng cũ.
	Postcondition: x là phần tử ở đuôi của danh sách
	*/

	void deleteElement(int i);
	/*
	Loại khỏi danh sách phần tử ở vị trí i.
	Precondition: 1 <= i <= length().
	Postcondition: phần tử ở vị trí thứ i bị loại khỏi danh sách, các phần tử từ vị trí thứ i + 1 được lùi về sau 1 vị trí.
	*/

	item findElement(int i);
	/*
	Tìm phần tử ở vị trí thứ i
	Precondition: 1 <= i <= length()
	Postcondition: trả về phần tử ở vị trí i
	*/
};
