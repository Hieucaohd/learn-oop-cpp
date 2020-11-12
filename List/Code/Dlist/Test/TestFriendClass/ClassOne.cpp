#pragma once
#include <iostream>
#include <string>
#include "ClassTwo.cpp"
using namespace std;

class ClassOne
{
public:
	ClassOne(string name, string firstName)
	{
		ten = name;
		ho = firstName;
	}
	friend class ClassTwo;
private:
	string ten;
	string ho;
};