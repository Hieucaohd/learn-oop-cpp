#include "Ong.h"

template <class item>
void Ong<item>::setColor(string color)
{
	this->color = color;
}

template <class item>
void Ong<item>::setFirstName(string firstName)
{
	this->firstName = firstName;
}

template <class item>
string Ong<item>::getColor()
{
	return color;
}

template <class item>
string Ong<item>::getFirstName()
{
	return firstName;
}
