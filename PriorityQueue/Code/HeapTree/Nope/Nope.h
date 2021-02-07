#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Khai bao truoc lop PriorityQueue.*/
class CPriorityQueue;

/* Dinh nghia kieu cua du lieu vao kieu cua muc uu tien.*/
typedef char typeOfData;
typedef int typeOfPriority;

class CNope
{
private:
public:
	typeOfData m_data; // bien luu lai du lieu cua phan tu.
	typeOfPriority m_priority; // bien luu lai gia tri uu tien cua phan tu.
	CNope *m_left; 
	CNope *m_right;

	friend class CPriorityQueue; // khai bao lop ban.

	CNope();
	/* Constructor rong.
	 * */

	CNope(const typeOfData &data_parameter, const typeOfPriority &priority_parameter);
	/* Constructor.
	 * */

	~CNope();
	/* Destructor.
	 * */

	CNope operator = (const CNope &nope_parameter);
	/* Dinh nghia toan tu gan.
	 * Khi muon su dung toan tu gan, ta nen tao constructor truoc.
	 * Khong nen gan luon nhu the nay: CNope nope_2 = nope_1;
	 * Ma nen lam nhu the nay:
	 * 		Cnope nope_2;
	 * 		nope_2 = nope_1;
	 * */

	friend void copyTree(CNope * from_nope, CNope * &to_nope);
	/* Sao chep cac dinh tu from_nope sang to_nope.
	 * Phuc vu cai dat toan tu gan va constructor copy.
	 * */

	friend ostream &operator << (ostream &output, CNope nope_parameter);
	/* Dinh nghia phep in phan tu.
	 * */
	
	friend ostream &operator << (ostream &output, CNope *nope_parameter);
	/* Dinh nghia phep in con tro cua phan tu.
	 * */
};
