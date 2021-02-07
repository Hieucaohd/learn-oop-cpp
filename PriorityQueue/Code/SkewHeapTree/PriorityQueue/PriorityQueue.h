#include <iostream>
#include <string>
#include <vector>

#include "../Nope/Nope.h"

using namespace std;

/* Hang uu tien duoc cai dat boi CTDL cay nghieng.*/
class CPriorityQueue
{
private:
public:
	CNope *m_root;
	CPriorityQueue();
	/*Constructor rong.
	 * */

	~CPriorityQueue();
	/* Destructor.
	 * */
	
	void insert(const typeOfData &data_parameter, const typeOfPriority &priority_parameter);
	/* Them mot phan tu vao cay.
	 * Tao ra cay chi co mot dinh chua phan tu moi, sau do hop
	 * nhat cay do voi cay root.
	 * */

	void insert(CNope &nope_parameter);
	/* Them mot phan tu vao cay.
	 * Tao ra cay chi co mot dinh chua phan tu moi, sau do hop
	 * nhat cay do voi cay root.
	 * */

	CNope deleteMin();
	/* Loai bo goc cay, sau do hop nhat cay con trai
	 * va cay con phai.
	 * */

	CNope findMin();
	/* Tra ve phan tu o goc cay.
	 * */

	void decreaseKey(CNope *root_ptr, const typeOfPriority &key);
	/* Giam khoa cua cay.
	 * */

	friend CNope * mergeTree(CNope * &root_ptr_1, CNope * &root_ptr_2);
	/* Hop nhat 2 cay nghieng root_ptr_1 va root_ptr_2.
	 * */

	friend void swapTree(CNope * &root_ptr_1, CNope * &root_ptr_2);
	/* Dung de doi cho 2 cay.
	 * */
};
