#include "ClassOne.cpp"
#include "ClassTwo.cpp"

int main(int argc, char const *argv[])
{
	ClassOne hieu("hieu", "cao");
	ClassTwo ptrHieu(hieu);
	cout << ptrHieu.getNameFromClassOne();
	return 0;
}