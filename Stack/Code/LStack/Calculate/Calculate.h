#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Stack/Stack.h"
using namespace std;

void outputInfix(string *infix, int number_of_elements);
/* Postcondition: xuat ra man hinh bieu thuc infix.
 * */

void outputPostfix(vector<string> postfix);
/* Postcondition: xuat ra man hinh bieu thuc postfix.
 * */

bool isOperation(string operation);
/* Kiem tra xem phan tu operation co phai la phep toan hay khong.
 * */

bool isParentheses(string parentheses);
/* Kiem tra xem phan tu parentheses co phai dau ngoac don hay khong.
 * */

bool compareOperationInInfixWithStack(string operation_in_infix, string operation_in_stack);
/* So sanh phep toan trong bieu thuc infix voi phep toan trong stack.
 *
 * Postcondition: neu operation trong infix nho hon hoac bang 
 * operation trong stack thi tra ve true, con neu lon hon thi 
 * tra ve false.
 * */

vector<string> changeInfixToPostfix(string *infix, int number_of_elements);
/* Chuyen bieu thuc infix thanh bieu thuc postfix.
 * */

int calculate(string *array, int size_of_array);
/* Tinh bieu thuc postfix.
 * */
