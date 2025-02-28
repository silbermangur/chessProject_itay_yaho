#include "board.h"
#include <iostream>
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

board::board() : _board(STARTING_BOARD) 
{
	bool color = true;
	int i = 0;
	
	_boardArray[0] = new rook(color);  
	_boardArray[1] = new knight(color);
	_boardArray[2] = new bishop(color); 
	_boardArray[3] = new king(color);
	_boardArray[4] = new queen(color);
	_boardArray[5] = new bishop(color); 
	_boardArray[6] = new knight(color);
	_boardArray[7] = new rook(color);

	for (i = 8; i < 16; i++)
	{
		_boardArray[i] = new pawn(color);
	}

	for (i = 16; i < 48; i++)
	{
		_boardArray[i] = nullptr;
	}

	color = false;
	for (i = 48; i < 56; i++)
	{
		_boardArray[i] = new pawn(color);
	}
	_boardArray[56] = new rook(color);
	_boardArray[57] = new knight(color);
	_boardArray[58] = new bishop(color);
	_boardArray[59] = new king(color);
	_boardArray[60] = new queen(color);
	_boardArray[61] = new bishop(color);
	_boardArray[62] = new knight(color);
	_boardArray[63] = new rook(color);
}

board::~board()
{
	for (int i = 0; i < (SIZE_OF_BOARD * SIZE_OF_BOARD); i++)
	{
		delete(_boardArray[i]);
	}
}

string board::getBoard()
{
	return _board;
}

void board::setBoard(string board)
{
	_board = board;
}

piece* board::getPiece(int index)
{
	return _boardArray[index];
}

bool board::getTurn()
{
	if (_board[64] != 48)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void board::setTurn(bool &turn)
{
	if (turn == true)
	{
		this->_board[64] = '0';
		turn = false;
	}
	else
	{
		this->_board[64] = '1';
		turn = true;
	}
}

bool board::isCheck()
{
	return false;
}

void board::playMove(int src, int dest)
{
	if (_boardArray[dest] != nullptr)
	{
		delete(_boardArray[dest]);
	}
	_boardArray[dest] = _boardArray[src];
	_boardArray[src] = nullptr;
	
}

bool board::getMove()
{
	return false;
}

void board::printBoard()
{
	string board = getBoard();
	int index = 0;

	for (int line = 0; line < SIZE_OF_BOARD; line++)
	{
		for (int i = 0; i < SIZE_OF_BOARD; i++)
		{
			cout << board[index] << " ";
			index++;
		}
		cout << endl;
	}
	cout << endl;
}

