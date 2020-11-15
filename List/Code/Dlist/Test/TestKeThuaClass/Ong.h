#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class item>
class Ong
{
private:
	string color;
	string firstName;
public:
	void setColor(string color);
	void setFirstName(string firstName);
	string getColor();
	string getFirstName();
};