#include "Calculate.h"

int convertStringNumberToIntNumber(char number)
{
	if (number == '0')
	{
		return 0;
	}
	else if (number == '1')
	{
		return 1;
	}
	else if (number == '2')
	{
		return 2;
	}
	else if (number == '3')
	{
		return 3;
	}
	else if (number == '4')
	{
		return 4;
	}
	else if (number == '5')
	{
		return 5;
	}
	else if (number == '6')
	{
		return 6;
	}
	else if (number == '7')
	{
		return 7;
	}
	else if (number == '8')
	{
		return 8;
	}
	else 
	{
		return 9;
	}
}

string convertIntNumberToStringNumber(int number)
{
	switch (number)
	{
		case 0:
			return "0";
			break;
	
		case 1:
			return "1";
			break;
		
		case 2:
			return "2";
			break;
		
		case 3:
			return "3";
			break;		

		case 4:
			return "4";
			break;		

		case 5:
			return "5";
			break;		

		case 6:
			return "6";
			break;		

		case 7:
			return "7";
			break;		

		case 8:
			return "8";
			break;		

		case 9:
			return "9";
			break;		
	}
}

int pow(int base, int exponent)
{
	int result = 1;
	for (int i = 1; i <= exponent; i++)
	{
		result *= base;
	}
	return result;
}

int toInt(string string_number)
{
	int result = 0;
	for (int i = 0; i < string_number.length(); i++)
	{
		int number = convertStringNumberToIntNumber(string_number[i]);
		int decimal_base = pow(10, string_number.length() - 1 - i);
		result += number * decimal_base;
	}

	return result;
}

string toString(int number)
{
	string result;
	if (number == 0)
	{
	 	return "0";   
	}
	
	while (number != 0)
	{
		result += convertIntNumberToStringNumber(number % 10);
		number /= 10;
	}

	string final_result;

	for (int i = result.length() - 1; i >= 0; i--)
	{
		final_result += result[i];
	}
	
	return final_result;
}

/*
string toString(int number)
{
    string result;
    ostringstream convert;
    convert << number;
    result = convert.str();
	return result;
}
*/

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

bool isParenthesesOpen(string parentheses)
{
	if (parentheses == "(")
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
		if (infix[i] == "(")
		/* Neu phan tu trong infix la dau mo ngoac*/
		{
		    stack.push(infix[i]);
		}
		else if (infix[i] == ")")
		/* Neu phan tu la dau dong ngoac.*/
		{
			while (!stack.isStackEmpty() && (stack.getTop() != "("))
			/* Lay cac phan tu trong stack ra.*/
			{
				postfix.push_back(stack.getTop());
				stack.pop();
			} // End while.
			stack.pop(); // bo dau mo ngoac ra khoi stack.
		}
		else if (isOperation(infix[i]))
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
				while ((compareOperationInInfixWithStack(infix[i], stack.getTop())) && (!stack.isStackEmpty()) && (stack.getTop() != "("))
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

int calculatePostfix(vector<string> postfix)
{
	CStack stack;
	for (int i = 0; i < postfix.size(); i++)
	{
		if (!isOperation(postfix[i]))
		/* Neu thanh phan la toan hang.*/
		{
			stack.push(postfix[i]);    
		}
		else
		/* Neu phan tu la phep toan.*/
		{
			/* Thi ta lay 2 toan hang o dinh ngan xep ra.*/
			if (postfix[i] == "+")
			/* Phep cong.*/
			{
				int number_1 = toInt(stack.pop());	
				int number_2 = toInt(stack.pop());
				int result = number_1 + number_2;
				stack.push(toString(result));
			}
			if (postfix[i] == "-")
			/* Phep tru.*/
			{
				int number_1 = toInt(stack.pop());	
				int number_2 = toInt(stack.pop());
				int result = number_1 - number_2;
				stack.push(toString(result));
			}
			if (postfix[i] == "*")
			/* Phep nhan.*/
			{
				int number_1 = toInt(stack.pop());	
				int number_2 = toInt(stack.pop());
				int result = number_1 * number_2;
				stack.push(toString(result));
			}
			if (postfix[i] == "/")
			/* Phep chia.*/
			{
				int number_1 = toInt(stack.pop());	
				int number_2 = toInt(stack.pop());
				int result = number_1 / number_2;
				stack.push(toString(result));
			}
		}
	}
	
	int result = toInt(stack.pop());
	return result;
}
