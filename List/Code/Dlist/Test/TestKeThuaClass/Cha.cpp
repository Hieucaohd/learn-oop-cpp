#pragma once
#include "Ong.cpp"

class Cha: public Ong
{
private:
	string colorHair;
public:
	void setColorHair(string colorHair)
	{
		this->colorHair = colorHair;
	}

	string getColorHair()
	{
		return this->colorHair;
	}

};
