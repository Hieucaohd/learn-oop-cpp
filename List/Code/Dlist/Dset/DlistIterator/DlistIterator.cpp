#include "DlistIterator.h"

DlistIterator::DlistIterator(Dlist &L)
{
	LPtr = &L;
	current = -1;
}

void DlistIterator::start()
{
	current = 0;
}

bool DlistIterator::valid() const
{
	return (0 <= current && current <= LPtr->last); 
}

void DlistIterator::advance()
{
	if (valid())
	/* Neu vi tri hien thoi nam trong danh sach.*/
	{
		current += 1;
	}
}

item DlistIterator::currentElement() const
{
	if (valid())
	/* Neu vi tri hien thoi nam trong danh sach.*/
	{
		return LPtr->elements[current];
	}
	else
	/* Neu vi tri hien thoi khong nam trong danh sach.*/
	{
		item null_return;
		return null_return;
	}
}

void DlistIterator::add(const item &x)
{
	if (valid())
	{
		if (LPtr->length() < LPtr->size)
		// Mảng element[] chưa đầy.
		{
			LPtr->last++;
			for (int k = LPtr->last; k > current; k--)
			{
				LPtr->elements[k] = LPtr->elements[k - 1];
			}
			LPtr->elements[current] = x;
			current++;
		}
		else
		// Mảng element[] đầy.
		{
			item *newArray = new item[LPtr->size * 2 + 1];
			if (newArray != NULL)
			{
				for (int k = 0; k <= current - 1; k++)
				{
					// Sao chép các phần từ từ 0 -> current + 1 của element sang newArray.
					newArray[k] = LPtr->elements[k];
				}
				newArray[current] = x; // chèn x vào vị trí hiện thời.
				
				for (int k = current + 1; k <= LPtr->last + 1; k++)
				{
					// sao chép các phần tử từ current -> last của element sang newArray.
					newArray[k] = LPtr->elements[k - 1];
				}

				delete [] LPtr->elements;
				LPtr->elements = newArray;
				LPtr->last++;
				LPtr->size = LPtr->size * 2 + 1;
			}
		}
		current++; // phần tử hiện thời vẫn là phần tử hiện thời.
	}
}

void DlistIterator::remove()
{
	if (valid())
	{
		for (int k = current; k <= LPtr->last - 1; k++)
		{
			// Các phần tử đi đứng sau phần tử hiện thời lùi về sau.
			LPtr->elements[k] = LPtr->elements[k + 1];
		}
	}
}
