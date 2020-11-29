#include "Dset.cpp"

int main(int argc, char const *argv[])
{
	int numberOfElements;
	cout << "\n\n\t\t NHAP SO PHAN TU CUA TAP: ";
	cin >> numberOfElements;
	Dset tapDong1(100);
	tapDong1.inputElementsOfDlist(numberOfElements);
	tapDong1.inputKeyForDset();
	tapDong1.outputKeyOfDset();
	
	typeOfKey key;
	cout << "\n\n\t\t NHAP KEY MA BAN MUON TIM KIEM: ";
	cin >> key;
	if (tapDong1.searchElementByKeyInDsetSortedUseRecursive(key, 1, tapDong1.length()))
	{
		cout << "\t\t Tim duoc roi." << endl;
	}
	else
	{
		cout << "\t\t Khong tim duoc." << endl;
	}
	//tapDong1.outputElementsOfDlist();
	return 0;
}