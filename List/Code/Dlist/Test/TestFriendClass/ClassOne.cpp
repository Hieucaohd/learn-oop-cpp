#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef int typeOfElement;
typedef int typeOfKey;
struct item 
{
	typeOfElement item;
	typeOfKey key;
};

class ClassTwo;
class ClassOne
{
public:
	friend class ClassTwo;
	ClassOne(int kichCo)
	{
		size = kichCo;
		last = -1;
		element = new item[kichCo];
	}
	~ClassOne()
	{
		delete [] element;
	}

	void input(int numbers)
	{
		cout << "\n\n\t\t NHAP CAC PHAN TU CUA MANG: \n";
		last = numbers;
		for (int i = 0; i < numbers; ++i)
		{

			cout << "Nhap phan tu thu " << i << ": ";
			cin >> element[i].item >> element[i].key;
		}
		cout << endl;
	}
	void output()
	{
		cout << "\n\n\t\t CAC PHAN TU CUA MANG: ";
		for (int i = 0; i < last; ++i)
		{
			cout << element[i].item << "(" << element[i].key << ")" << " ";
		}
		cout << endl;
	}
private:
	item *element;
	int size;
	int last;
};