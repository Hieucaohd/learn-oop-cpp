#pragma once 
#include <iostream>
#include <string>
#include "../Dlist/Dlist.h"
using namespace std;

class DlistIterator
{
private:
    Dlist *LPtr;
    int current;
public:
	DlistIterator(Dlist &L);
	/* Constructor.
	 * */

    void start();
    /* Postcondition: vị trí hiện thời là vị trí đầu tiên của danh sách.
	 * */

    bool valid() const;
    /* Postcondition: trả về true nếu tại vị trí hiện thời có phần tử 
	 * trong danh sách, trả về false nếu không.
	 * */

    void advance();
	/* Precondition: hàm valid() trả về true
	 * Postcondition: vị trí hiện thời là vị trí tiếp theo trong danh sách
	 * */

    item currentElement() const;
	/* Precondition: ham valid() tra ve true.
	 * Postcondition: tra ve phan tu hien thoi trong danh sach.
	 * */

    void add(const item &x);
	/* Precondition: hàm valid() trả về true.
	 * Postcondition: phần tử x được xem vào trước phần tử hiện thời, phần tử hiện thời 
	 * vẫn còn là phần tử hiện thời.
	 * */

    void remove();
	/* Precondition: hàm valid() trả về true.
	 * Postcondition: phần tử hiện thời bị loại khỏi danh sách, phần tử đi 
	 * sau nó thành phần tử hiện thời.
	 * */
};
