#include "Shape.cpp"

class Rectangle: public Shape
{
public:
	// Constructor
	Rectangle(double length = 0.0, double width = 0.0): Shape("rectangle")
	{
		this->length = length;
		this->width = width;
	}
	// Dis-constructor
	~Rectangle()
	{

	}

	// Hàm trả về chiều dài của hình chữ nhật
	double getLength() const
	{
		return length;
	}

	// Hàm trả về chiều rộng của hình chữ nhật
	double getWidth() const
	{
		return width;
	}

	// Hàm tính chu vi hình chữ nhật
	double perimeter() const
	{
		return 2 * (length + width);
	}

	// Hàm tính diện tích hình chữ nhật
	double area() const
	{
		return length * width;
	}

	// Hàm in ra thông tin của hình chữ nhật
	void printInformation(ostream &out = cout) const
	{
		Shape::printInformation(out);
		out << " and of length " << length << " and of width " << width;
	}
private:
	double length;
	double width;
};

	