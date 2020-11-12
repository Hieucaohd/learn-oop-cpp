#pragma once
#include <iostream>
#include <string>
using namespace std;

class Shape
{
public:
	// Constructor
	Shape(const string &s = " ")
	{
		name = s;
	}
	// Dis-contructor
	~Shape()
	{

	}
	
	// Hàm trả về tên của hình
	string getName() const
	{
		return name;
	}

	// Hàm tính chu vi
	virtual double perimeter() const = 0;
	
	// Hàm tính diện tích
	virtual double area() const = 0;
	
	// Hàm so sánh diện tích của 2 hình
	bool operator <= (const Shape &sh) const
	{
		return area() <= sh.area();
	}
	
	// Hàm in ra diện tích của hình
	virtual void printInformation(ostream &out = cout) const
	{
		out << name << " of area " << area(); 
	}
private:
	string name; // Tên của hình
};