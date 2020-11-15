#include "Cha.cpp"
template <class item>
class Chau: public Cha<item>
{
public:
	void helloChau()
	{
		cout << "Hello chau" << endl;
	}

	void speak()
	{
		if (Ong<item>::getFirstName() == "cao")
		{
			cout << "chau ho cao" << endl;
		}
		else
		{
			cout << "chau ho khac ong va cha" << endl;
		}
	}
};