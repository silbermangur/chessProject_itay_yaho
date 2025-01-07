#include <iostream>
#include "board.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#define	STARTING_BOARD "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"

using namespace std;

int findIndex(int& x, int& y)
{
	x -= 1;
	y = SIZE - y;
	return y * SIZE + x;
}

int main()
{
	// string boardArray[SIZE][SIZE] = { "rnbkqbnr", "pppppppp", "########", "########", "########", "########", "PPPPPPPP", "RNBKQBNR",1 };
	string boardString = STARTING_BOARD; 
	board b;
	b.setBoard(boardString);  
	b.printBoard(); 
	cout << endl;

	int x = 8;
	int y = 7;
	int i = findIndex(x, y);
	/*
	boardString[i] = '+';
	b.setBoard(boardString);
	b.printBoard();
	*/

	int a[4] = {3,3,4,4};

	//rook r(true);
	//r.move(a);

	//bishop b2(true);
	//b2.move(a);

	//queen q(true);

	king k(true);
	int* arr = k.move(a);

	for (int i = 0; i < SIZE; i++)
	{
		if (arr != NULL  &&  arr[i] != -1)
		{
			boardString[arr[i]] = '+';
		}
	}	

	b.setBoard(boardString);
	b.printBoard();
	
	return 0;
}
