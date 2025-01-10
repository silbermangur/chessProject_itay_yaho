#pragma once
#include "piece.h"


#define SIZE 8 

class board
{
public:
	board();
	~board();
	string getBoard();  
	void setBoard(string board);
	bool getTurn();
	void setTurn();
	bool isCheck();
	string playMove();
	bool  getMove();
	void printBoard();

private:
	piece* _boardArray[SIZE * SIZE];
	string _board;
};
