#pragma once
#include <iostream>
#include "ClassOne.cpp"
using namespace std;

class ClassTwo
{
public:
	ClassTwo(const ClassOne &hihi)
	{
		one = &hihi;
	}
	void advanceLast()
	{
		one->last += 1;
	}
private:
	ClassOne *one;
};