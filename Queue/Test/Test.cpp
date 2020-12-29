#include <iostream>
using namespace std;

class CNope
{
public:
	string m_data; // phan du lieu.
	CNope *m_next; 
	friend class CQueue;
	/* Khia bao lop ngan xep la ban.
	 * */

	CNope(const string &data_parameter);
	/* Constructor.
	 * */

	~CNope();
	/* Destructor.
	 * */
};

CNope::CNope(const string &data_parameter)
{
	m_data = data_parameter;
	m_next = NULL;
}

CNope::~CNope()
{
	
}

void enQueue(CNope *m_tail,string data_parameter)
{
	/* Tao mot phan tu moi.*/
	CNope *new_nope = new CNope(data_parameter);
	
	/* Them phan tu moi vao duoi hang doi.*/
	if (m_tail == NULL)
	/* Neu hang doi rong.*/
	{
	    m_tail = new_nope;
		m_tail->m_next = m_tail; // de tao danh sach lien ket vong tron.
	}
	else
	/* Neu hang doi khong rong.*/
	{
		new_nope->m_next = m_tail->m_next;
		m_tail->m_next = new_nope;
		m_tail = new_nope;
	}
}

int main(int argc, char *argv[])
{
	CNope *m_tail = NULL;
	enQueue(m_tail, "hieu");

	cout << m_tail->m_next->m_data << endl;
	/*
	if (m_tail == m_tail->m_next)
	{
	    cout << "Bang nhau." << endl;
	}
	*/
	return 0;
}
