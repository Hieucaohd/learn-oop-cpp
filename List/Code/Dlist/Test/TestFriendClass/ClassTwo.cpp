#pragma once
#include <iostream>
#include "ClassOne.cpp"
using namespace std;

class ClassTwo
{
public:
	ClassTwo(const ClassOne &onePara)
	{
		one = onePara;
	}
	~ClassTwo()
	{
		delete one;
	}
	string getNameFromClassOne()
	{
		return one->ten;
	}
private:
	ClassOne *one;
};