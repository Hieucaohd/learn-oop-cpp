#include <iostream>
#include <string>
#include <vector>
#include "Dictionary/Dictionary.h"

using namespace std;

int main(int argc, char *argv[])
{
	CDictionary *dic = new CDictionary();
	bool is_success;
	typeOfData data;
	typeOfKey key;

	dic->insert(data = 100, key = 3, is_success);
	dic->insert(data = 300, key = 814, is_success);
	if (is_success)
	/* Neu them thanh cong.*/
	{
	    cout << "Them thanh cong." << endl;
	}

	dic->deleteElementByKey(key = 3);

	if (dic->search(key = 814, data))
	{
	    cout << "Tim thay va gia tri la: " << data << endl;
	}
	else
	{
		cout << "Khong tim thay." << endl;
	}
	return 0;
}
