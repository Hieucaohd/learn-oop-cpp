#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef int typeOfItem;
typedef int typeOfKey;
struct item
{
	typeOfKey key;
	typeOfItem item;
};

class DlistIterator;

// Dlist = Dynamic List: danh sách cấp phát động


class Dlist
{
public:
	friend class DlistIterator; // công cụ iterator làm hàm bạn

	Dlist()
	{
		// Constructor: khởi tạo một mảng rỗng
		element = NULL;
		size = 0;
		last = -1;
	}

	Dlist(int m)
	{
		/* 
		Constructor: khởi tạo cỡ của mảng được cấp phát động 
		với m = cỡ của mảng được cấp phát động
		Precondition: m nguyên dương
		Postcondition: một danh sách rỗng được khởi tạo với khả năng tối đa chứa m phần tử
		*/
		element = new item[m];
		if (element != NULL)
		{
			size = m;
			last = -1;
		}
	}

	Dlist(const Dlist &L)
	{
		// Constructor - copy.
		element = new item[L.size];
		size = L.size;
		last = L.last;
		for (int k = 0; k <= last; k++)
		{
			element[k] = L.element[k];
		}
	}

	Dlist & operator = (const Dlist &L)
	{
		// Định nghĩa toán tử "=" để copy từ đối tượng L.
		if (size != L.size)
		{
			delete [] element;
			element = new item[L.size];
			size = L.size;
		}
		last = L.last;
		for (int k = 0; k <= last; k++)
		{
			element[k] = L.element[k];
		}
		return *this;
		
	}

	~Dlist()
	{
		// Dis-constructor: thu hồi bộ nhớ được cấp phát động cho mảng.
		delete [] element;
	}

	bool isDlistEmpty() const
	{
		/* 
		Kiểm tra xem một danh sách có rỗng không.
		Postcondition: trả về true nếu danh sách rỗng và false nếu không.
		*/
		return last < 0;
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
		Nếu length() >= size thì ta sẽ cấp phát động một mảng mới có kích cỡ gấp đôi mảng cũ.
		Precondition: 1 <= i <= length().
		Postcondition: các phần tử của danh sách kể từ vị trí thứ i được đẩy ra sau một vị trí, phần tử x nằm ở vị trí thứ i.
		*/
		if (1 <= i && i <= length())
		{
			if (length() < size) 
			// Mảng element[] chưa đầy
			{
				last++;
				for (int k = last; k >= i; k--)
				{
					element[k] = element[k - 1];
				}
				element[i - 1] = x;
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
					}
					newArray[i - 1] = x;

					for (int k = i; k <= last + 1; k++)					
					{
						// Sao chép phần tử từ i -> last trong element[] sang newArray[].
						newArray[k] = element[k - 1];
					}
					delete [] element;
					element = newArray;
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
		Nếu length() >= size thì ta sẽ cấp phát động một mảng mới có kích thước gấp đôi mảng cũ.
		Postcondition: x là phần tử ở đuôi của danh sách
		*/
		if (length() < size)
		// Mảng element[] chưa đầy
		{
			last++;
			element[last] = x;
		}
		else
		// Mảng element[] đầy
		{
			item *newArray = new item[size * 2 + 1];
			if (newArray != NULL)
			{
				for (int k = 0; k <= last; k++)
				{
					newArray[k] = element[k];
				}
				newArray[last + 1] = x;	// thêm x vào cuối mảng
				delete [] element;
				element = newArray;
				last++;
				size = 2 * size + 1;
			}
		}	
	}

	void deleteElement(int i)
	{
		/*
		Loại khỏi danh sách phần tử ở vị trí i
		Precondition: 1 <= i <= length()
		Postcondition: phần tử ở vị trí thứ i bị loại khỏi danh sách, các phần tử từ vị trí thứ i + 1 được lùi về sau 1 vị trí
		*/
		if (1 <= i && i <= length())
		{
			for (int k = i - 1; k < last; k++)
			{
				element[k] = element[k + 1];
			}
			last--;
		}
	}

	item findElement(int i)
	{
		/*
		Tìm phần tử ở vị trí thứ i
		Precondition: 1 <= i <= length()
		Postcondition: trả về phần tử ở vị trí i
		*/
		if (1 <= i && i <= length())
		{
			return element[i - 1];
		}
	}

	void inputDlistElements(int numberElements)
	{
		/*
		Nhập các phần tử cho danh sách.
		Nếu số phần tử cần nhập lớn hơn kích thước của danh sách 
		thì ta cấp phát một mảng mới có kích thước gấp đôi mảng cũ.
		*/
		last = numberElements - 1;
		if (numberElements < size)
		// Số phần tử cần nhập nhỏ hơn kích cỡ đã được cấp phát cho mảng element[].
		{
			cout << "\n\n\t\t NHAP DANH SACH \n";
			for (int k = 0; k <= last; k++)
			{
				fflush(stdin);
				cout << "Nhap phan tu thu " << k + 1 << ": ";
				cin >> element[k].item;
			}
		}
		else
		// Số phần tử cần nhập lớn hơn kích cỡ đã được cấp phát cho mảng element[].
		{
			size = size + numberElements; // cấp phát thêm cho mảng số phần tử bằng chính cố phần tử cần nhập
			delete [] element;
			element = new item[size];
			for (int k = 0; k <= last; k++)
			{
				fflush(stdin);
				cout << "Nhap phan tu thu " << k + 1 << ": ";
				cin >> element[k].item;
			}
		}
	}

	void outputDlistElements()
	{
		if (!isDlistEmpty())
		// Danh sách không rỗng
		{
			cout << "\n\n\t\t CAC PHAN TU CUA MANG: ";
			for (int k = 0; k <= last; k++)
			{
				cout << element[k].item << " ";
			}
			cout << endl;
		}
		else
		// Danh sách rỗng
		{
			cout << "Danh sach rong" << endl;
		}
	}

	// void setKeyOfElements(const typeOfKey &key, const int &i)
	// {
	// 	element[i - 1].key = key;
	// }
private:
	item *element;
	int size; // kích cỡ của mảng cấp phát động element[]. 
	int last; // số lượng phần tử có trong danh sách length() =  last + 1.
};