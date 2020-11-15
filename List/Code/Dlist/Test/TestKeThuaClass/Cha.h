#include "Ong.h"

template <class item>
class Cha: public Ong<item>
{
private:
	string colorHair;
public:
	void speak();
	void setColorHair(string colorHair);
	string getColorHair();
};
