#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../Stack/Stack.h"
using namespace std;

int convertStringNumberToIntNumber(char number);
/* Chuyen chu so o dang string thanh chu so o dang int.
 * Postcondition: tra ve dang int cua chu so.
 * */

string convertIntNumberToStringNumber(int number);
/* Chuyen chu so o dang int sang chu so o dang string.
 * Postcondition: tra ve chu so o dang string.
 * */

int pow(int base, int exponent);
/* Ham lay mu.
 * Postcondition: tra ve gia tri cua base^exponent.
 * */

int toInt(string string_number);
/* Chuyen so o dang string thanh so o dang int.
 * Postcondition: tra ve so o dang int.
 * */

string toString(int number);
/* Chuyen mot so o dang int sang dang string.
 * Postcondition: tra ve so o dang string.
 * */

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

int calculatePostfix(vector<string> postfix);
/* Tinh gia tri bieu thuc postfix.
 * */
