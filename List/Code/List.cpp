#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class item>
class List
{
public:
	static const int MAX = 50; // khai báo cỡ của mảng.

	List()
	{
		// Constructor khởi tạo một danh sách rỗng.
		last = -1;
		current = -1;
	}
	
	~List()
	{
		// Dis-constructor.
	}

	// FUNCTIONS:
	bool empty() const
	{
		// Kiểm tra xem một danh sách có rỗng không.
		// Postcondition: trả về true nếu danh sách rỗng và false nếu không.
		return last < 0;
	}

	int length() const
	{
		// Xác định độ dài của danh sách.
		// Postcondition: trả về số phần tử trong danh sách.
		return last + 1;
	}

	void insert(const item &x, int i)
	{
		// LƯU Ý: phần tử thứ i của danh sách (i = 1, 2, 3,...) được lưu trong thành phần element[i - 1] của mảng
		// Xen phần tử x vào vị trí thứ i trong danh sách.
		// Precondition: length() < MAX và 1 <= i <= length().
		// Postcondition: các phần tử của danh sách kể từ vị trí thứ i được đẩy ra sau một vị trí, phần tử x nằm ở vị trí thứ i.
		if (length() < MAX && 1 <= i && i <= length())
		{
			last++;
			for (int k = last; k >= i; k--)
			{
				element[k] = element[k - 1];
			}
			element[i - 1] = x;
		}
		else
		{
			cout << "Khong the xen phan tu x vao vi tri i trong day" << endl;
		}
	}

	void append(const item &x)
	{
		// Thêm phần tử x vào đuôi danh sách.
		// Precondition: length() < MAX.
		// Postcondition: x là phần tử ở đuôi của danh sách
		if (length() < MAX)
		{
			last ++;
			element[last] = x;
		}
		
	}

	void delete(int i)
	{
		// Loại khỏi danh sách phần tử ở vị trí i
		// Precondition: 1 <= i <= length()
		// Postcondition: phần tử ở vị trí thứ i bị loại khỏi danh sách, các phần tử từ vị trí thứ i + 1 được lùi về sau 1 vị trí
		if (1 <= i && i <= length())
		{
			for (int k = i - 1; k < last; k++)
			{
				element[k] = element[k + 1];
			}
			last --;
		}
	}

	item fineElement(int i) const
	{
		// Tìm phần tử ở vị trí thứ i
		// Precondition: 1 <= i <= length()
		// Postcondition: trả về phần tử ở vị trí i
		if (1 <= i && i <= length())
		{
			return element[i - 1];
		}
		else
		{
			cout << "Ngoai pham vi cua danh sach" << endl;
		}	
	}

	// ITERATION:
	void start()
	{
		// Postcondition: vị trí hiện thời là vị trí đầu tiên của danh sách
		current = 0;
	}

	bool valid() const
	{
		// Postcondition: trả về true nếu tại vị trí hiện thời có phần tử trong danh sách, trả về false nếu không
		return current >= 0 && current <= last;
	}

	void advance()
	{
		// Precondition: hàm valid() trả về true
		// Postcondition: vị trí hiện thời là vị trí tiếp theo trong danh sách
		if (valid())
		{
			current++;
		}
		
	}

	item current() const
	{
		// Precondition: hàm valid() trả về true
		// Postcondition: trả về phần tử hiện thời của danh sách
		if (valid())
		{
			return element[current];
		}
		
	}

	void add(const item &x)
	{
		// Precondition: length() < MAX và hàm valid() trả về true
		// Postcondition: phần tử x được xem vào trước phần tử hiện thời, phần tử hiện thời vẫn còn là phần tử hiện thời
		if (length() < MAX && valid())
		{
			last++;
			for (int k = last; k > current; k--)
			{
				element[k] = element[k - 1];
			}
			element[current] = x;
			current++;
		}
	}

	void remove()
	{
		// Precondition: hàm valid() trả về true
		// Postcondition: phần tử hiện thời bị loại khỏi danh sách, phần tử đi sau nó thành phần tử hiện thời
		if (valid())
		{
			for (int k = current; k < last; k++)
			{
				element[k] = element[k + 1];
			}
			last --;
		}

	}

private:
	item element[MAX]; // mảng lưu các phần tử của danh sách
	int last; // đanh dấu vị trí cuối cùng trong danh sách last = length() - 1 

	int current; /*
	Đánh dấu vị trí hiện thời, nó là chỉ số mà element[current] chứa phần tử hiện thời của danh sách, 
	Ví dụ: current = 3 thì phần tử hiện thời là phần tử ở vị trí 4 của danh sách
	*/
};