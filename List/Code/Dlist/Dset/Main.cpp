#include <iostream>
#include <string>
#include "Dlist/Dlist.h"
#include "DlistIterator/DlistIterator.h"
#include "Dset/Dset.h"

using namespace std;

int main(int argc, char *argv[])
{
	Dset tap(3);

	/* Nhap cac phan tu cua tap va xuat ra tap.*/
	tap.inputDset(4);
	tap.outputDset();

	/* Tim phan tu co key lon nhat trong tap.*/
	cout << "Key lon nhat trong tap la: ";
	cout << tap.maxKeyOfDset() << endl;

	/* Xoa phan tu co key la 3.*/
	tap.DsetDeleteElementByKey(3);

	/* Xuat ra tap.*/
	tap.outputDset();
	return 0;
}
