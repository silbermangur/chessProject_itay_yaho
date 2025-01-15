#pragma once
#include "piece.h"

#define	STARTING_BOARD "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0" // 0 - white turn

class board
{
public:
	board();
	~board();
	string getBoard();  
	void setBoard(string board);
	piece* getPiece(int index);
	bool getTurn();
	void setTurn(bool &turn);
	bool isCheck();
	void playMove(int src, int dest);
	bool  getMove();
	void printBoard();

private:
	piece* _boardArray[SIZE_OF_BOARD * SIZE_OF_BOARD];
	string _board;
};
