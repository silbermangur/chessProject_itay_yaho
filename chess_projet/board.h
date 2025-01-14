#pragma once
#include "piece.h"

#define	STARTING_BOARD "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"
#define SIZE 8 

class board
{
public:
	board();
	~board();
	string getBoard();  
	void setBoard(string board);
	piece* getPiece(int index);
	bool getTurn();
	void setTurn();
	bool isCheck();
	void playMove(int src, int dest);
	bool  getMove();
	void printBoard();

private:
	piece* _boardArray[SIZE * SIZE];
	string _board;
};
