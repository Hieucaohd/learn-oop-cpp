#include <iostream>

using namespace std;

void printNumbers(const int * arrayIndex, const int &numberElementArrayIndex, const int * arrayInitial)
{
	for (int i = 0; i < numberElementArrayIndex; i++)
	{
		cout << arrayInitial[ arrayIndex[i] ] << " ";
	}
	cout << endl;
}

void subSequences(const int * arrayInitial, const int &subInitial, const int &numberElement)
{
	int *arrayIndex = new int[numberElement];

	arrayIndex[0] = -1;
	int numberOrder = 0;
	int sub = 0;

	while (numberOrder >= 0)
	/*comment*/
	{
		arrayIndex[numberOrder] ++;

		if (arrayIndex[numberOrder] < numberElement)
		{
			if ( sub + arrayInitial[ arrayIndex[numberOrder] ] <= subInitial )
			{
			    if ( sub + arrayInitial[ arrayIndex[numberOrder] ] == subInitial )
			    {
			        printNumbers(arrayIndex, numberOrder + 1, arrayInitial);
			    }
				else
				{
					sub += arrayInitial[ arrayIndex[numberOrder] ];
					arrayIndex[numberOrder + 1] = arrayIndex[numberOrder];
					numberOrder ++;
				}
			}
		}
		else
		{
			numberOrder --;
			sub -= arrayInitial[ arrayIndex[numberOrder] ];
		}
	}
	
	delete [] arrayIndex;
}

void subSequencesDeQuy(const int *arrayInitial, const int &subInitial, const int &numberElement, int numberOrder, int sub, int *arrayIndex)
{
	if (sub == subInitial)
	{
		printNumbers(arrayIndex, numberOrder, arrayInitial);
	}
	
	for (int i = arrayIndex[numberOrder]; i <= numberElement - 1; i++)
	{
		arrayIndex[numberOrder] = i;
		arrayIndex[numberOrder + 1] = i + 1;

		if (sub < subInitial)
		{
			subSequencesDeQuy(arrayInitial, subInitial, numberElement, numberOrder + 1, sub + arrayInitial[i], arrayIndex);
		}
	}
}

void thu()
{
	int numberElement = 5;
	int subInitial = 10;

	int * arrayInitial = new int[numberElement];
	arrayInitial[0] = 1;
	arrayInitial[1] = 3;
	arrayInitial[2] = 5;
	arrayInitial[3] = 7;
	arrayInitial[4] = 9;

	subSequences(arrayInitial, subInitial, numberElement);

	delete [] arrayInitial;
}

void inputOutputArray(int *array, const int &numberElement)
{
	cout << "Nhap mang : " << endl;
	for (int i = 0; i < numberElement; i++)
	{
		cin >> array[i];
	}
	
	system("clear");

	cout << "Mang: ";
	for (int i = 0; i < numberElement; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void thu1()
{
	int subInitial = 10;

	int numberElement = 5;
	int * arrayInitial = new int[numberElement];
	arrayInitial[0] = 1;
	arrayInitial[1] = 3;
	arrayInitial[2] = 5;
	arrayInitial[3] = 7;
	arrayInitial[4] = 9;

	int * arrayIndex = new int[numberElement];
	arrayIndex[0] = 0;

	subSequencesDeQuy(arrayInitial, subInitial, numberElement, 0, 0, arrayIndex);
	delete [] arrayInitial;
}

int main(int argc, char *argv[])
{
	int subInitial;
	cout << "Nhap tong ban dau: "; cin >> subInitial;
	int numberElement;
	cout << "Nhap so luong phan tu cua mang: "; cin >> numberElement;

	int * arrayInitial = new int[numberElement];

	inputOutputArray(arrayInitial, numberElement);

	subSequences(arrayInitial, subInitial, numberElement);

	cout << endl;

	int * arrayIndex = new int[numberElement];
	arrayIndex[0] = 0;
	subSequencesDeQuy(arrayInitial, subInitial, numberElement, 0, 0, arrayIndex);

	delete [] arrayInitial;
	return 0;
}
