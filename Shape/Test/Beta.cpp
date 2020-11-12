#include "Alpha.cpp"

class Beta: public Alpha
{
private:
	int y;
protected:
	int z;
public:
	Beta()
	{
		y = 3;
		z = 4;
	}

	void foo()
	{
		cout << "y = " << y << endl;
	}

	void bar() 
	{
		cout << "z = " << z << endl;
	}
};