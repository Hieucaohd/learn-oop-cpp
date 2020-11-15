#include "ClassOne.cpp"
#include "ClassTwo.cpp"

int main(int argc, char const *argv[])
{
	ClassOne oneObj(12);
	ClassTwo twoObj(oneObj);
	twoObj.advanceLast();
	oneObj.input(10);
	oneObj.output();
	system("pause");
	return 0;
}