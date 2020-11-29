#include <iostream>
#include "../Dlist.h"
using namespace std;

class CDListIterator
{
private:
	CDList* m_Dlist_ptr; // bien con tro de quan li danh sach.
	int m_current; // vi tri hien thoi.
public:
	CDListIterator(CDList &L);
	/* Constructor kien tao.
	 * */

	~CDListIterator();
	/* Constructor ket thuc.
	 * */

	void start();
	/* Postcondition: dat vi tri hien thoi la 
	 * vi tri dau tien trong danh sach L.
	 * */

	bool valid() const
	/* Postcondition: tra ve true neu vi tri hien thoi co 
	 * phan tu trong danh sach, va tra ve false neu khong.
	 * */
	
	void advance();
	/* Precondition: ham valid() tra ve true.
	 * Postcondition: vi tri hien thoi la vi tri tiep theo 
	 * trong danh sach.
	 * */
	
	typeOfElement & current() const
	/* Precondition: ham valid() tra ve true.
	 * Postcondition: tra ve phan tu o vi tri hien thoi 
	 * cua danh sach.
	 * */

	void add(const typeOfElement &element_parameter);
	/* Precondition: ham valid() tra ve true.
	 * Postcondition: phan tu element_parameter duoc xen truoc 
	 * vao phan tu hien thoi, phan tu hien thoi van la phan tu
	 * hien thoi.
	 * */

	void remove();
	/* Precondition: ham valid() tra ve true.
	 * Postcondition: phan tu hien thoi bi loai khoi danh sach
	 * phan tu di sau no tro thanh phan tu hien thoi.
	 * */
}
