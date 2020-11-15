#include "DlistIterator.cpp"

int main(int argc, char const *argv[])
{
	system("cls");
	

	int numberElements;
	cout << "\n\n\t\t NHAP SO PHAN TU CUA DANH SACH: ";
	cin >> numberElements;
	

	Dlist L(100);
	L.inputDlistElements(numberElements);
	

	DlistIterator iterL(L);
	iterL.start();
	cout << "Current element now: " << iterL.currentElement().item << endl;
	iterL.advance();
	cout << "Current element now: " << iterL.currentElement().item << endl;
	L.outputDlistElements();
	system("pause");
	return 0;
}