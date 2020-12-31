#include "Dlist.h"

Dlist::Dlist()
{
	elements = NULL;
	size = 0;
	last = -1;
}

Dlist::Dlist(int m)
{
	elements = new item[m];
	if (elements != NULL)
	{
		size = m;
		last = -1;
	}
}

Dlist::Dlist(const Dlist &L)
{
	elements = new item[L.size];
	size = L.size;
	last = L.last;
	for (int k = 0; k <= last; k++)
	{
		elements[k] = L.elements[k];
	}
}

Dlist & Dlist::operator = (const Dlist &L)
{
	if (size != L.size)
	/* Neu kich co cua danh sach hien tai nho hon danh sach L.*/
	{
		delete [] elements;
		elements = new item[L.size];
		size = L.size;
	}
	last = L.last;
	for (int k = 0; k <= last; k++)
	{
		elements[k] = L.elements[k];
	}
	return *this;
	
}

Dlist::~Dlist()
{
	delete [] elements;
}

void Dlist::inputElementsOfDlist(int numberElements)
{
	last = numberElements - 1;
	if (numberElements < size)
	// Số phần tử cần nhập nhỏ hơn kích cỡ đã được cấp phát cho mảng elements[].
	{
		cout << "\n\n\t\t NHAP DANH SACH \n";
		for (int k = 0; k <= last; k++)
		{
			fflush(stdin);
			cout << "Nhap phan tu thu " << k + 1 << ": ";
			cin >> elements[k].data;
		}
	}
	else
	// Số phần tử cần nhập lớn hơn kích cỡ đã được cấp phát cho mảng elements[].
	{
		size = size + numberElements; // cấp phát thêm cho mảng số phần tử bằng chính cố phần tử cần nhập.
		delete [] elements;
		elements = new item[size];
		for (int k = 0; k <= last; k++)
		{
			fflush(stdin);
			cout << "Nhap phan tu thu " << k + 1 << ": ";
			cin >> elements[k].data;
		}
	}
}

void Dlist::outputElementsOfDlist()
{
	if (!isDlistEmpty())
	// Danh sách không rỗng.
	{
		cout << "\n\n\t\t CAC PHAN TU CUA DANH SACH: ";
		for (int k = 0; k <= last; k++)
		{
			cout << elements[k].data << " ";
		}
		cout << endl;
	}
	else
	// Danh sách rỗng.
	{
		cout << "Danh sach rong" << endl;
	}
}

void Dlist::setKeyOfElement(const typeOfKey &key, const int &i)
{
	elements[i - 1].key = key;
}

bool Dlist::isDlistEmpty() const
{
	return last < 0;
}

int Dlist::length() const
{
	/* 
	Xác định độ dài của danh sách.
	Postcondition: trả về số phần tử trong danh sách.
	*/
	return last + 1;
}

void Dlist::insert(const item &x, int i)
{
	if (1 <= i && i <= length())
	{
		if (length() < size) 
		// Mảng elements[] chưa đầy.
		{
			last++;
			for (int k = last; k >= i; k--)
			{
				elements[k] = elements[k - 1];
			}
			elements[i - 1] = x;
		}
		else 
		// Mảng elements[] đầy.
		{
			item *newArray = new item[2 * size + 1];
			if (newArray != NULL)
			{
				for (int k = 0; k <= i - 2; k++) 
				{
					/* 
					Sao chép các phần tử từ 0 -> i - 2 trong elements[] sang newArray[],
					đồng thời gán phần tử newArray[i - 1] = x. 
					*/
					newArray[k] = elements[k];
				}
				newArray[i - 1] = x;

				for (int k = i; k <= last + 1; k++)					
				{
					// Sao chép phần tử từ i -> last trong elements[] sang newArray[].
					newArray[k] = elements[k - 1];
				}
				delete [] elements;
				elements = newArray;
				last++;
				size = 2 * size + 1;	
			}	
		}	
	}	
}

void Dlist::append(const item &x)
{
	if (length() < size)
	// Mảng elements[] chưa đầy.
	{
		last++;
		elements[last] = x;
	}
	else
	// Mảng elements[] đầy.
	{
		item *newArray = new item[size * 2 + 1];
		if (newArray != NULL)
		{
			for (int k = 0; k <= last; k++)
			{
				newArray[k] = elements[k];
			}
			newArray[last + 1] = x;	// thêm x vào cuối mảng.
			delete [] elements;
			elements = newArray;
			last++;
			size = 2 * size + 1;
		}
	}	
}

void Dlist::deleteElement(int i)
{
	if (1 <= i && i <= length())
	/* Neu vi tri can xoa nam trong danh sach.*/
	{
		for (int k = i - 1; k < last; k++)
		{
			elements[k] = elements[k + 1];
		}
		last--;
	}
}

item Dlist::findElement(int i)
{
	if (1 <= i && i <= length())
	/* Neu vi tri can chen nam trong danh sach.*/
	{
		return elements[i - 1];
	}
	else
	/* Neu vi tri can tim khong nam trong danh sach.*/
	{
		item null_return;
		return null_return;
	}
}
