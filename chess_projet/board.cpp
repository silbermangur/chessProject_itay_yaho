#include "board.h"
#include <iostream>

string board::getBoard()
{
	return _board;
}

void board::setBoard(string board)
{
	_board = board; 
}

bool board::getTurn()
{
	return _turn;
}

bool board::isCheck()
{
	return _isCheck;
}

string board::playMove()
{

	return _board;
}

bool board::getMove()
{
	return false;
}

void board::printBoard()
{
	string board = getBoard();
	int index = 0;

	for (int line = 0; line < SIZE; line++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << board[index] << " ";
			index++;
		}
		cout << endl;
	}
}

