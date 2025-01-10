#include <iostream>
#include "board.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "knight.h"

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
	
	int x = 8;
	int y = 7;
	int f = findIndex(x, y);
	/*
	boardString[i] = '+';
	b.setBoard(boardString);
	b.printBoard();
	*/

	int a[4] = {7,7,0,7};

	rook r(true);
	

	//bishop b2(true);

	//queen q(true);

	//king k(true);

	//pawn p(false);

	//knight n(true);
	int* arr = r.move(a);
	

	int i = 0;
	for (i = 0;i < SIZE;i++) 
	{
		if (!(arr[i] >= 0 && arr[i] <= 64))
		{
			break;
		}
	}
	i -= 1;
	boardString[arr[i]] = boardString[arr[0]];
	boardString[arr[0]] = '#';
	/*
	for (int i = 0; i < SIZE; i++)
	{
		if (arr != NULL  &&  arr[i] >= 0 && arr[i] <= 64)
		{
			boardString[arr[i]] = '+';
		}
	}	
	*/
	b.setBoard(boardString);
	b.printBoard();
	

	return 0;
}
