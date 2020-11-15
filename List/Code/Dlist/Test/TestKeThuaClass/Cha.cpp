#include "Cha.h"

template <class item>
void Cha<item>::speak()
{
	if (Ong<item>::getColor() == "black")
	{
		cout << "cha cung da den" << endl;
	}
	else
	{
		cout << "cha mau da khac" << endl;
	}
}

template <class item>
void Cha<item>::setColorHair(string colorHair)
{
	this->colorHair = colorHair;
}

template <class item>
string Cha<item>::getColorHair()
{
	return this->colorHair;
}


