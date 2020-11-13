#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ong
{
private:
	string color;
	string firstName;
public:
	void setColor(string color)
	{
		this->color = color;
	}
	void setFirstName(string firstName)
	{
		this->firstName = firstName;
	}
	string getColor()
	{
		return color;
	}
	string getFirstName()
	{
		return firstName;
	}
};
