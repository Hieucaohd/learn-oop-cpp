#pragma once 
#include <iostream>
#include "Dlist.cpp"
using namespace std;

template <class item>
class DlistIterator
{
public:
	DlistIterator(const Dlist<item> &L)
    {
        // Constructor.
        LPtr = &L;
        current = -1;
    }

    void start()
    {
        // Postcondition: vị trí hiện thời là vị trí đầu tiên của danh sách
        current = 0;
    }

    bool valid() const
    {
        // Postcondition: trả về true nếu tại vị trí hiện thời có phần tử trong danh sách, trả về false nếu không
        return (0 <= current && current <= LPtr->last); 
    }

    void advance()
    {
        /*
        Precondition: hàm valid() trả về true
		Postcondition: vị trí hiện thời là vị trí tiếp theo trong danh sách
        */
        if (valid())
        {
            current += 1;
        }
    }

    item currentElement() const
    {
        if (valid())
        {
            return LPtr->element[current];
        }
    }

    void add(const item &x)
    {
        /*
        Precondition: hàm valid() trả về true
		Postcondition: phần tử x được xem vào trước phần tử hiện thời, phần tử hiện thời vẫn còn là phần tử hiện thời
        */
        if (valid())
        {
            if (LPtr->length() < LPtr->size)
            // Mảng element[] chưa đầy
            {
                LPtr->last++;
                for (int k = LPtr->last; k > current; k--)
                {
                    LPtr->element[k] = LPtr->element[k - 1];
                }
                LPtr->element[current] = x;
                current++;
            }
            else
            // Mảng element[] đầy
            {
                item *newArray = new item[LPtr->size * 2 + 1];
                if (newArray != NULL)
                {
                    for (int k = 0; k <= current - 1; k++)
                    {
                        // Sao chép các phần từ từ 0 -> current + 1 của element sang newArray
                        newArray[k] = LPtr->element[k];
                    }
                    newArray[current] = x; // chèn x vào vị trí hiện thời
                    
                    for (int k = current + 1; k <= LPtr->last + 1; k++)
                    {
                        // sao chép các phần tử từ current -> last của element sang newArray
                        newArray[k] = LPtr->element[k - 1];
                    }

                    delete [] LPtr->element;
                    LPtr->element = newArray;
                    LPtr->last++;
                    LPtr->size = LPtr->size * 2 + 1;
                }
            }
            current++; // phần tử hiện thời vẫn là phần tử hiện thời
        }
    }

    void remove()
    {
        /*
        Precondition: hàm valid() trả về true
		Postcondition: phần tử hiện thời bị loại khỏi danh sách, phần tử đi sau nó thành phần tử hiện thời
        */
        if (valid())
        {
            for (int k = current; k <= LPtr->last - 1; k++)
            {
                // Các phần tử đi đứng sau phần tử hiện thời lùi về sau
                LPtr->element[k] = LPtr->element[k + 1];
            }
        }
    }
private:
    const Dlist<item> *LPtr;
    int current;
};