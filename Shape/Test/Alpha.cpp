#pragma once
#include <iostream>
#include <string>
using namespace std;

class Alpha
{
private:
	int w;
protected:
	int x;
public:
	Alpha()
	{
		w = 1;
		x = 2;
	}

	void foo()
	{
		cout << "w = " << w << endl;
	}

	virtual void bar()
	{
		cout << "x = " << x << endl;
	}
};