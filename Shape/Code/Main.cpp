#include "Rectangle.cpp"
#include "Circle.cpp"

int main(int argc, char const *argv[])
{
	Shape *sh1 = new Rectangle(3, 2);

	cout << sh1->getName() << endl;
	cout << sh1->getLength() << endl;
	sh1->printInformation();

	Shape *sh2 = new Circle(3);
	sh2->getRadius();
	delete sh1;
	return 0;
}