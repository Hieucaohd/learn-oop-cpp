#include "Chau.cpp"

int main(int argc, char const *argv[])
{
	Chau chau1;
	chau1.setColor("black");
	cout << chau1.getColor() << endl;
	chau1.setColorHair("yellow");
	cout << chau1.getColorHair() << endl;
	return 0;
}