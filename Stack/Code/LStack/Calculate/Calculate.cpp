#include "Calculate.h"

bool isPhepToan(phepToan)
{
	if (phepToan == "+" || phepToan == "-" || phepToan == "*" || phepToan == "/")
	/*comment*/
	{
	    return true;
	}
	else
	/*comment*/
	{
		return false;
	}
}

bool isDauNgoac(dauNgoac)
{
	if (dauNgoac == "(" || dauNgoac == ")")
	/*comment*/
	{
	    return true;
	}
	else
	/*comment*/
	{
		return false;
	}
	
}

string checkEqual(operation_1, operation_2)
{
	/* Kiem tra xem phep toan co ngang bang hay khong.*/
	if (operation_1 == "-" || operation_1 == "+")
	{
		return ">=";
	}
	else
	{
		if (operation_2 == "*" || operation_2 == "/")
		{
		 	return ">=";   
		}
		else
		{
			return "<";
		}
	}
}

int calculate(string *array, int size_of_array)
{
	string *postfix = new string[size_of_array];
	int tail_index = 0;
	CStack stack = new CStack();
	for (int i = 0; i < size_of_array; i++)
	{
		if (!isPhepToan(array[i]) && !isDauNgoac(array[i]))
		/* Neu la toan hang.*/
		{
		    
		}
		
	}

	delete stack;
	delete [] postfix;
}
