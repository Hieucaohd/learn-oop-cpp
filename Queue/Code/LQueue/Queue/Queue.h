#pragma once
#include <iostream>
#include "../Nope/Nope.h"
using namespace std;

/* Cai dat hang doi boi danh sach lien ket vong tron.*/
class CQueue
{
private:
	CNope *tail;
public:
	CQueue();
	/* Constructor: khoi tao mot hang doi rong.
	 * */
	
	CQueue(const CQueue &Q);
	/* Constructor copy.
	 * */

	~CQueue();
	/* Destructor.
	 * */
	
	CQueue operator = (const CQueue &Q);
	/* Dinh nghia toan tu gan.
	 * */
	
	bool isQueueEmpty();
	/* Postcondition: tra ve true neu hang doi rong
	 * va tra ve false neu hang doi khong rong.
	 * */
	
	void enQueue(const typeOfData & data_parameter);
	/* Them phan tu vao duoi hang doi.
	 * Postcondition: phan tu duoc them vao cuoi hang doi.
	 * */

	typeOfData deQueue();
	/* Lay ra phan tu o dau hang doi, dong thoi 
	 * tra ve gia tri cua phan tu do
	 * Postcondition: xoa phan tu o dau hang doi,
	 * tra ve gia tri cua phan tu do.
	 * */
	
	typeOfData getHead();
	/* Tra ve phan tu o dau hang doi.
	 * Postcondition: tra ve gia tri cua phan tu o dau hang doi
	 * ma khong lam thay doi hang doi.
	 * */
};
