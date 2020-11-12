#include "Shape.cpp"

class Circle: public Shape
{
public:
	// Hằng số pi
	const double PI = 3.14;

	// Constructor
	Circle(double radius = 0.0): Shape("circle")
	{
		this->radius = radius;
	}
	// Dis-constructor
	~Circle()
	{

	}

	// Hàm trả về bán kính của hình tròn
	double getRadius() const
	{
		return radius;
	}

	// Hàm trả về chu vi của hình tròn
	double perimeter() const
	{
		return 2 * radius * PI;
	}

	// Hàm trả về diện tích của hình tròn
	double area() const
	{
		return radius * radius * PI;
	}

	// Hàm in ra thông tin của hình tròn
	void printInformation(ostream &out = cout) const
	{
		Shape::printInformation(out);
		out << " of radius " << radius;
	}
private:
	double radius; // bán kính của hình tròn
};