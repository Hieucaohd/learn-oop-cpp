#include "Dset.h"

Dset::Dset(int m): Dlist(m)
{

}

bool Dset::isDsetEmpty() 
{
	isDlistEmpty();
}

void Dset::DsetAppend(const item &x)
{
	if (!searchElementByKey(x.key))
	// Phần tử x chưa tồn tại trong tập hợp.
	{
		append(x); // them phan tu x vao cuoi tap.
	}
	else
	{
		cout << "Phan tu da ton tai trong tap" << endl;
	}
}

void Dset::DsetDeleteElementByKey(typeOfKey k)
{
	for (int i = 1; i <= length(); i++)
	{
		if (findElement(i).key == k)
		{
			deleteElement(i);
			break;
		}
	}
}

bool Dset::searchElementByKey(typeOfKey k)
{
	for (int i = 1; i <= length(); i++)
	{
		if (findElement(i).key == k)
		{
			return true;
		}
		return false;
	}
}

typeOfKey Dset::maxKeyOfDset()
{
	if (!isDsetEmpty())
	{
		typeOfKey maxKey = findElement(1).key;
		for (int i = 1; i <= length(); i++)
		{
			if (findElement(i).key > maxKey)
			{
				maxKey = findElement(i).key;
			} 
		}

		return maxKey;
	}
}

typeOfKey Dset::minKeyOfDset()
{
	if (!isDsetEmpty())
	/* Neu tap khong rong.*/
	{
		typeOfKey minKey = findElement(1).key;
		for (int i = 1; i <= length(); i++)
		{
			if (findElement(i).key < minKey)
			{
				minKey = findElement(i).key;
			}
		}
		
		return minKey;
	}
}

void Dset::inputDset(int numberElements)
{
	Dlist::inputElementsOfDlist(numberElements);
	inputKeyForDset();
}

void Dset::outputDset()
{
	outputKeyOfDset();
}

void Dset::inputKeyForDset()
{
	if (!isDsetEmpty())
	{
		cout << "\n\n\t\t NHAP KHOA KEY CHO CAC PHAN TU CUA TAP HOP: \n";
		for (int i = 1; i <= length(); i++)
		{
			typeOfKey key;
			cout << "Nhap khoa key cua phan tu thu " << i << ": ";
			cin >> key;
			setKeyOfElement(key, i);
		}            
	}
	else
	{
		cout << "Tap khong co phan tu nao, vui long nhap cac phan tu cua tap" << endl;
	}
}

void Dset::outputKeyOfDset()
{
	if (!isDsetEmpty())
	{
		cout << "\n\n\t\t XUAT KHOA KEY CUA CAC PHAN TU: \n";
		for (int i = 1; i <= length(); i++)
		{
			cout << findElement(i).data << "(" << findElement(i).key << ")" << " "; 
		}
		cout << endl;
	}
	else
	{
		cout << "Tap khong co phan tu nao, vui long nhap cac phan tu cua tap" << endl;
	}
}

/*
Doi voi tap da duoc sap xep.
Cac key duoc sap xep theo thu tu tu be den lon.
Phan tu co key be nhat duoc xep o vi tri dau tien trong tap.
*/

typeOfKey Dset::minKeyOfDsetSorted()
{
	if (!isDsetEmpty())
	// Neu tap khong rong.
	{
		return findElement(1).key;
	}
	else
	{
		cout << "Tap rong." << endl;
	}
}

typeOfKey Dset::maxKeyOfDsetSorted()
{
	if (!isDsetEmpty())
	// Neu tap khong rong.
	{
		return findElement(length()).key;
	}
	else
	{
		cout << "Tap rong." << endl;
	}
}

void Dset::DsetSortedInsert(const item &x)
{
	int i = 1;
	while(i <= length())
	{
		if (x.key < findElement(i).key)
		{
			insert(x, i);
			break;
		}
		else if (x.key == findElement(i).key)
		{
			break;
		}
		i++;
	}

	if (i > length())
	{
		append(x);
	}
}

void Dset::DsetSortedDeleteElementByKey(typeOfKey key)
{
	if (!isDsetEmpty())
	// Neu tap khong rong.
	{
		for (int i = 1; i <= length(); i++)
		{
			if (findElement(i).key == key)
			{
				deleteElement(i);
				break;
			}
			else if (findElement(i).key > key)
			// Neu phan tu khong co trong tap.
			{
				cout << "Phan tu khong co trong tap." << endl;
				break;
			}
		}
	}
}

bool Dset::searchElementByKeyInDsetSorted(typeOfKey key)
{
	int bottom, top, mid;
	bottom = 1;
	top = length();
	while(bottom <= top)
	{
		mid = (top + bottom) / 2;
		if (key == findElement(mid).key)
		{
			return true;
		}
		else if (key > findElement(mid).key)
		{
			bottom = mid + 1;
		}
		else
		{
			top = mid - 1;
		}
	}

	return false;
}

bool Dset::searchElementByKeyInDsetSortedUseRecursive(typeOfKey key, int bottom, int top)
{
	if (bottom > top)
	{
		return false;
	}
	int mid = (bottom + top) / 2;
	if (key == findElement(mid).key)
	{
		return true;
	}
	else if (key > findElement(mid).key)
	{
		searchElementByKeyInDsetSortedUseRecursive(key, mid + 1, top);
	}
	else
	{
		searchElementByKeyInDsetSortedUseRecursive(key, bottom, mid - 1);
	}
}
