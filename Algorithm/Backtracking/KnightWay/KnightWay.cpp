#include <iostream>
#include <stdio.h>

using namespace std;

struct Position
{
	int x; // toa do x la hang doc.
	int y; // tao do y la hang ngang.
	int i; // de luu i hien tai.
};

void printPosition(Position *positionArray, const int &count, int size)
{
	/* Phan khai bao.*/
	int ** chessBoard = new int* [size];

	for (int i = 0; i < size; i++)
	{
		chessBoard[i] = new int[size];
	}

	/* Phan tao ban co va in ban co.*/
	for (int i = 0; i < count; i++)
	{
		chessBoard[positionArray[i].x][positionArray[i].y] = i + 1;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%2d ", chessBoard[i][j]);
		}
		cout << endl;
	}
	cout << endl;

	/* Phan thu hoi bo nho.*/
	for (int i = 0; i < size; i++)
	{
		delete [] chessBoard[i];
		chessBoard[i] = NULL;
	}
	delete [] chessBoard;
	chessBoard = NULL;
}

bool shouldGoNext(int ** chessBoard, const int &x, const int &y, const int &size)
{
	if (x < 0 || y < 0 || x > size - 1 || y > size - 1)
	{
	    return false;
	}
	else if (chessBoard[x][y] == 1)
	{
		return false;
	}

	return true;
}

void knightWayKhongDeQuy(int ** chessBoard, int x, int y, const int &size)
{
	/* Mang de luu vi tri.*/
	Position * positionArray = new Position[size * size];

	/* Danh dau vi tri ban dau.*/
	chessBoard[x][y] = 1;
	positionArray[0].x = x;
	positionArray[0].y = y;

	/* Cac buoc di cua x va y*/
	int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
	int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};

	int i = -1;
	int count = 1;

	while (count >= 1)
	{
		i++;

		if (i >= 0 && i <= 7)
		/* Ta se xem het cac buoc di
		 * x + X[i], y + Y[i] la mot buoc di.*/
		{
			if (count == size * size)
			/* Neu da den o cuoi cung trong ban co.*/
			{
				/* In ra ban co voi cac buoc di.*/
			    printPosition(positionArray, count, size);

				/* Quay lai xem cac truong hop khac.*/
				count --;
				
				chessBoard[x][y] = 0;
				i = positionArray[count].i;
				x = positionArray[count - 1].x;
				y = positionArray[count - 1].y;
			}
			else if (shouldGoNext(chessBoard, x + X[i], y + Y[i], size))
			/* Neu buoc di tiep theo thoa man.*/
			{
				x = x + X[i];
				y = y + Y[i];

				chessBoard[x][y] = 1; // danh dau.

				positionArray[count].x = x;
				positionArray[count].y = y;
				positionArray[count].i = i; // luu lai i hien tai de ty quay lui thi xet tiep.

				count ++;
				i = -1;
			}
		}
		else
		/* Quay lui.*/
		{
			count --;

			chessBoard[x][y] = 0; // bo danh dau.
			i = positionArray[count].i; // lay lai i truoc do.
			x = positionArray[count - 1].x; // lay lai x truoc do.
			y = positionArray[count - 1].y; // lay lai y truoc do.
		}
	} // End while.

	delete [] positionArray;
}

void thu()
{
	/* Phan khai bao.*/
	int size;
	cout << "Nhap kich co cua ban co: ";
	cin >> size;

	/* Tao mang 2 chieu la ban co.*/
	int ** chessBoard = new int* [size];

	for (int i = 0; i < size; i++)
	{
		chessBoard[i] = new int[size];
	}

	/* Phan nao chua co quan ma thi dat la 0.*/
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			chessBoard[row][col] = 0;
		}
	}


	/* Phan goi ham.*/
	knightWayKhongDeQuy(chessBoard, 2, 2, size);

	/* Phan thu hoi bo nho.*/
	for (int i = 0; i < size; i++)
	{
		delete [] chessBoard[i];
		chessBoard[i] = NULL;
	}

	delete [] chessBoard;
	chessBoard = NULL;
}

int main(int argc, char *argv[])
{
	thu();
	return 0;
}
