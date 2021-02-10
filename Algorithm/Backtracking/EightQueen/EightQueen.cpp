#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printArray(int *array, const int &size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Dong thu " << i << " cot thu " << array[i] << endl;
	}
	cout << endl;
}

void printArray(int *array)
{
	for (int i = 0; i < 8; i++)
	{
		cout << "Dong thu " << i << " cot thu " << array[i] << endl;
	}
	cout << endl;
}

int absuluteValue(int number)
{
	if (number >= 0)
	{
	    return number;
	}
	else
	{
		return -number;
	}
}



bool check(const int *arrayColumn, const int &rowCurrent)
{
	for (int rowBefore = 0; rowBefore < rowCurrent; rowBefore++)
	{
		bool isSameColumn = arrayColumn[rowBefore] == arrayColumn[rowCurrent];
		bool isSameDiagonal = absuluteValue(arrayColumn[rowBefore] - arrayColumn[rowCurrent]) == absuluteValue(rowBefore - rowCurrent);

		if (isSameColumn || isSameDiagonal)
		/* Neu cung dong hoac cung cot thi tra ve false.*/
		{
		    return false;
		}
	}

	return true;
}

void queen(int * arrayColumn, int row, int &count, const int &size)
{
	if (row > size - 1)
	/*comment*/
	{
		printArray(arrayColumn, size);
		count ++;
	}

	for (int i = 0; i < size; i++)
	/* Chay tung cot trong mot dong.*/
	{
		arrayColumn[row] = i;

		if (check(arrayColumn, row))
		/*comment*/
		{
			queen(arrayColumn, row + 1, count, size);   
		}
	}
}

void eightQueen()
{
	/* Mang de luu chi so cot cua moi dong.*/
	int *arrayColumn = new int[8];

	int row = 0;
	arrayColumn[row] = -1;

	int count = 0;

	while (row >= 0)
	/*comment*/
	{
		arrayColumn[row] ++;

		if (arrayColumn[row] <= 7)
		{
			if ( check(arrayColumn, row) )
			/* Kiem tra xem o hien tai co thoa man khong.*/
			{
			    if (row == 7)
			    /*comment*/
			    {
			        printArray(arrayColumn);
					count ++;
			    }
			    else
			    /*comment*/
			    {
			    	row ++;
					arrayColumn[row] = -1;
			    }
			}
		}
		else
		{
			row --;
		}
	} // End while.

	cout <<"So truong hop la : " << count << endl;
	
	delete [] arrayColumn;
}

int main(int argc, char *argv[])
{
	int *arrayColumn = new int[8];
	int row = 0;
	int count = 0;
	int size = 9;

	queen(arrayColumn, row, count, size);

	cout << count << endl;

	return 0;
}
