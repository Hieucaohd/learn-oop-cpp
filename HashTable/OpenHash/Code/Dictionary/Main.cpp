#include <iostream>
#include <string>
#include <vector>
#include "Dictionary/Dictionary.h"
#include "Entry/Entry.h"

using namespace std;

int main(int argc, char *argv[])
{
	system("clear");
	CDictionary *dic = new CDictionary();
	bool is_success;
	typeOfData data;
	typeOfKey key = 3;
	dic->insert(100, 3, is_success);

	if (dic->search(key, data))
	/* Neu tim thay.*/
	{
	    cout << "Tim thay va gia tri la: " << data << endl;
	}
	else
	/*comment*/
	{
		cout << "Khong tim thay." << endl;
	}

	dic->insert(1000, 814, is_success);
	if (dic->search(key = 814, data))
	/*comment*/
	{
	    cout << "Tim thay va gia tri la: " << data << endl;
	}
	else
	/*comment*/
	{
		cout << "Khong tim thay." << endl;
	}

	dic->deleteElementByKey(key = 814);
	if (dic->search(key = 814, data))
	/*comment*/
	{
	    cout << "Tim thay va gia tri la: " << data << endl;
	}
	else
	/*comment*/
	{
		cout << "Khong tim thay." << endl;
	}

	dic->insert(3232, 814, is_success);
	if (dic->search(key = 814, data))
	/*comment*/
	{
	    cout << "Tim thay va gia tri la: " << data << endl;
	}
	else
	/*comment*/
	{
		cout << "Khong tim thay." << endl;
	}
	return 0;
}
