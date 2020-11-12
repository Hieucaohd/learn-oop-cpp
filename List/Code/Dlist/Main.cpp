#include "DlistIterator.cpp"



int main(int argc, char const *argv[])
{
	system("cls");
	int numberElements;
	cout << "\n\n\t\t NHAP SO PHAN TU CUA DANH SACH: ";
	cin >> numberElements;
	Dlist<int> L(100);
	L.inputArrayElement(numberElements);
	DlistIterator<int> iterL(L);
	iterL.start();
	cout << "Current element now: " << iterL.currentElement() << endl;
	iterL.advance();
	cout << "Current element now: " << iterL.currentElement() << endl;
	L.outputArrayElement();
	system("pause");
	return 0;
}