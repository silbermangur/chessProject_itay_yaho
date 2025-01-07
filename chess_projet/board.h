#pragma once
#include "piece.h"

#define SIZE 8 

class board
{
public:
	string getBoard();
	void setBoard(string board);
	bool getTurn();
	bool isCheck();
	string playMove();
	bool  getMove();
	void printBoard();

private:
	//piece _boardArray[SIZE][SIZE];
	bool _turn;
	bool _isCheck;
	string _board;
};
