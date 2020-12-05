#include <iostream>
#include "../Code/LList/Nope/Nope.h"
using namespace std;

class CLinkedList
{
public:
	int m_length;
	CNope *m_head;	

	CLinkedList()
	{
		m_length = 0;
			
		m_head = new CNope(0);
		m_head->m_precede = m_head;
		m_head->m_next = m_head;
	}

	~CLinkedList()
	{
	
	}
	
	bool isListEmpty()
	{
		return (m_length == 0);
	}

	int length()
	{
		return m_length;
	}

	void appendElement(const typeOfData &data_parameter)
	{
		/* Tao mot thanh phan moi.*/
		CNope *new_nope = new CNope(data_parameter);
		
		/* Moc noi con tro duoi va new_nope.*/
		m_head->m_precede->m_next = new_nope;
		new_nope->m_precede = m_head->m_precede;
		
		/* Moc noi new_nope vao duoi danh sach.*/
		m_head->m_precede = new_nope;
		new_nope->m_next = m_head;

		/* Tang do dai cua danh sach them 1 don vi.*/
		m_length += 1; 
	}

	typeOfData findElement(int position)
	{
		if (1 <= position && position <= m_length)
		/* Neu vi tri can xoa nam trong danh sach.*/
		{
			/* Khoi tao con tro CHAY.*/
			CNope *cur = m_head;
			
			int count = 1;
			while (count <= position)
			/* Cho con tro CHAY chay den vi tri can tim.*/
			{
				cur =cur->m_next;
				count += 1;
			} // End while.

			return cur->m_data;
		}
		else
		/* Neu vi tri can tim khong nam trong danh sach.*/
		{
			cout << "Vi tri can tim khong nam trong danh sach." << endl;
		}
	}

	CNope findNope(int position)
	{
		if (1 <= position && position <= m_length)
		/* Neu vi tri can xoa nam trong danh sach.*/
		{
			/* Khoi tao con tro CHAY.*/
			CNope *cur = m_head;
			
			int count = 1;
			while (count <= position)
			/* Cho con tro CHAY chay den vi tri can tim.*/
			{
				cur =cur->m_next;
				count += 1;
			} // End while.

			return *cur;
		}
		else
		/* Neu vi tri can tim khong nam trong danh sach.*/
		{
			cout << "Vi tri can tim khong nam trong danh sach." << endl;
		}
			
	}
};

void thuHoi(CLinkedList &list1)
{
	/* Thu hoi bo nho tu list1.*/
	/* Khoi tao bien chay.*/
	CNope *cur = list1.m_head->m_next;

	while (cur != list1.m_head)
	/* Chay cho den khi nao cur == head.*/
	{
		CNope *delete_ptr = cur;
		cur = cur->m_next;
		delete delete_ptr;
	} // End while.
	
	delete list1.m_head;
}

void thuHoi2(CLinkedList &list1)
{
	CNope *cur = list1.m_head->m_next;
	int count = 1;
	while (count <= list1.length())
	/*comment*/
	{
		CNope *delete_ptr = cur;
		cur = cur->m_next;
		count += 1;
		delete delete_ptr;
	} // End while.
}

int main(int argc, char *argv[])
{
	system("clear");
	CLinkedList list1;
	list1.appendElement(1);
	list1.appendElement(999);
	list1.appendElement(200);

	cout << list1.m_head->m_data << endl;
	cout << list1.findElement(1) << endl;
	cout << list1.findElement(2) << endl;
	cout << endl;
	
	thuHoi2(list1);

	cout << list1.m_head->m_data << endl;
	cout << list1.findElement(1) << endl;
	cout << list1.findElement(2) << endl;
	cout << endl;

	cout << list1.length() << endl;
   	return 0;
}
