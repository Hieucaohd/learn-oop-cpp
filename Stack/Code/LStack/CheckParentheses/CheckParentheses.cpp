#include "CheckParentheses.h"

bool checkParentheses(string *array, int size_of_array)
{
	CStack stack1;

	if (size_of_array % 2 != 0)
	/* Neu so luong dau ngoac la so le.*/
	{
		return false;
	}
	else
	/* Neu so luong dau ngoac la so chan.*/
	{
		for (int i = 0; i < size_of_array; i++)
		{
			if (array[i] == "(")
			/* Neu gap dau mo ngoac.*/
			{
				stack1.push("("); // them dau mo ngoac "(" vao ngan xep.
			}
			else if (array[i] == ")")
			/* Neu gap dau dong ngoac.*/
			{
				if (stack1.isStackEmpty())
				/* Neu ngan xep rong.*/
				{
					return false;
				}
				else
				/* Neu ngan xep khong rong.*/
				{
					stack1.pop(); // bo mot dau mo ngoac "(" trong ngan xep ra.
				}
			}
		}

		if (stack1.isStackEmpty())
		/* Neu ngan xep rong.*/
		{
		    return true;
		}
		else
		/* Neu ngan xep khong rong.*/
		{
			return false;	
		}
	}
}
