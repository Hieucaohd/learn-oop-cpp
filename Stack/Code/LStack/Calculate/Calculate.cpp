#include "Calculate.h"

void outputInfix(string *infix, int number_of_elements)
{
	cout << endl; // cach dong cho dep.
	cout << "Bieu thuc infix: ";
	for (int i = 0; i < number_of_elements; i++)
	{
		cout << infix[i] << " ";
	}
	cout << endl; // cach dong cho dep.
}

void outputPostfix(vector<string> postfix)
{
	cout << endl; // cach dong cho dep.
	cout << "Bieu thuc postfix: ";
	for (int i = 0; i < postfix.size(); i++)
	{
		cout << postfix[i] << " ";
	}
	cout << endl; // cach dong cho dep.
}

bool isOperation(string operation)
{
	if (operation == "+" || operation == "-" || operation == "*" || operation == "/")
	{
	    return true;
	}
	else
	{
		return false;
	}
}

bool isParentheses(string parentheses)
{
	if (parentheses == "(" || parentheses == ")")
	{
	    return true;
	}
	else
	{
		return false;
	}
}

bool compareOperationInInfixWithStack(string operation_in_infix, string operation_in_stack)
{
	if (operation_in_infix == "+" || operation_in_infix == "-")
	{
		return true;
	}
	else
	{
		if (operation_in_stack == "*" || operation_in_stack == "/")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

vector<string> changeInfixToPostfix(string *infix, int number_of_elements)
{
	vector<string> postfix; // tao mang vector de chua bieu thuc postfix.
	CStack stack; // tao ngan xep de chua cac phep toan va dau ngoac.

	/* Duyet cac phan tu cua bieu thuc infix.*/
	for (int i = 0; i < number_of_elements; i++)
	{
		if (isOperation(infix[i]))
		/* Neu phan tu trong infix la phep toan.*/
		{
			if (stack.isStackEmpty())
			/* Neu stack rong.*/
			{
			    /* Thi them phep toan vao stack.*/
				stack.push(infix[i]);
			}
			else
			/* Neu stack khong rong.*/
			{
				while ((compareOperationInInfixWithStack(infix[i], stack.getTop())) && (!stack.isStackEmpty()))
				/* So sanh phep toan trong infix voi phep toan trong stack.
				 * Neu no nho hon hoac bang thi thuc hien cau lenh trong while.*/
				{
					postfix.push_back(stack.pop());
				} // End while.
				stack.push(infix[i]);
			}
		}
		else
		/* Neu phan tu trong infix la so hang.*/
		{
			postfix.push_back(infix[i]);
		}
	}

	while (!stack.isStackEmpty())
	/* Lay cac phan tu trong stack ra.*/
	{
		postfix.push_back(stack.getTop());
		stack.pop();
	} // End while.

	return postfix;
}

int calculate(vector<string> postfix)
{
	return 0;
}
