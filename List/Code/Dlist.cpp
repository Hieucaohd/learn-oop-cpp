#pragma once
#include <iostream>
#include <string>
#include "DlistIterator.cpp"
using namespace std;

// Dlist = Dynamic List: danh sách cấp phát động

template <class item>
class Dlist
{
public:
	friend class DlistIterator<item>;

	Dlist()
	{
		// Constructor: khởi tạo một mảng rỗng
		this->element = NULL;
		this->size = 0;
		this->last = -1;
	}

	Dlist(int m)
	{
		/* 
		Constructor: khởi tạo cỡ của mảng được cấp phát động 
		với m = cỡ của mảng được cấp phát động
		Precondition: m nguyên dương
		Postcondition: một danh sách rỗng được khởi tạo với khả năng tối đa chứa m phần tử
		*/
		this->element = new item[m];
		if (this->element != NULL)
		{
			this->size = m;
			this->last = -1;
		}
	}

	Dlist(const Dlist &L)
	{
		// Constructor - copy.
		this->element = new item[L.size];
		this->size = L.size;
		this->last = L.last;
		for (int k = 0; k <= last; k++)
		{
			this->element[k] = L.element[k];
		}
	}

	Dlist & operator = (const Dlist &L)
	{
		// Định nghĩa toán tử "=" để copy từ đối tượng L.
		if (this->size != L.size)
		{
			delete [] this->element;
			this->element = new item[L.size];
			this->size = L.size;
		}
		this->last = L.last;
		for (int k = 0; k <= last; k++)
		{
			this->element[k] = L.element[k];
		}
		return *this;
		
	}

	~Dlist()
	{
		// Dis-constructor: thu hồi bộ nhớ được cấp phát động cho mảng.
		delete [] this->element;
	}

	bool empty() const
	{
		/* 
		Kiểm tra xem một danh sách có rỗng không.
		Postcondition: trả về true nếu danh sách rỗng và false nếu không.
		*/
		return this->last < 0;
	}

	int length() const
	{
		/* 
		Xác định độ dài của danh sách.
		Postcondition: trả về số phần tử trong danh sách.
		*/
		return last + 1;
	}

	void insert(const item &x, int i)
	{
		/* 
		LƯU Ý: phần tử thứ i của danh sách (i = 1, 2, 3,...) được lưu trong thành phần element[i - 1] của mảng động.
		Xen phần tử x vào vị trí thứ i trong danh sách. 
		Nếu length() < size thì ta sẽ cấp phát động một mảng mới có kích cỡ gấp đôi mảng cũ.
		Precondition: 1 <= i <= length().
		Postcondition: các phần tử của danh sách kể từ vị trí thứ i được đẩy ra sau một vị trí, phần tử x nằm ở vị trí thứ i.
		*/
		if (1 <= i && i <= this->length())
		{
			if (this->length() < this->size) 
			// Mảng element[] chưa đầy
			{
				last++;
				for (int k = this->last; k >= i; k--)
				{
					this->element[k] = this->element[k - 1];
				}
				this->element[i - 1] = x;
			}
			else 
			// Mảng element[] đầy 
			{
				item *newArray = new item[2 * size + 1];
				if (newArray != NULL)
				{
					for (int k = 0; k <= i - 2; k++) 
					{
						/* 
						Sao chép các phần tử từ 0 -> i - 2 trong element[] sang newArray[],
						đồng thời gán phần tử newArray[i - 1] = x. 
						*/
						newArray[k] = element[k];
						newArray[i - 1] = x;
					}

					for (int k = i; k <= last + 1; k++)					
					{
						// Sao chép phần tử từ i -> last trong element[] sang newArray[].
						newArray[k] = this->element[k - 1];
					}
					delete [] this->element;
					this->element = newArray;
					last++;
					size = 2 * size + 1;	
				}	
			}	
		}	
	}

	void append(const item &x)
	{
		/* 
		Thêm phần tử x vào đuôi danh sách.
		Postcondition: x là phần tử ở đuôi của danh sách
		*/
		if (this->length() < this->size)
		// Mảng element[] chưa đầy
		{
			last++;
			this->element[last] = x;
		}
		else
		// Mảng element[] đầy
		{
			size++;
			item *newArray = new item[size];
			newArray = this->element;
			newArray[size - 1] = x;
			delete [] this->element;
			this->element = new item[size];
			this->element = newArray;
		}	
	}

	void delete(int i)
	{

	}

	item element(int i)
	{

	}
private:
	item *element;
	int size; // kích cỡ của mảng cấp phát động element[]. 
	int last; // số lượng phần tử có trong danh sách length() =  last + 1.

	
};