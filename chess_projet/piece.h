#pragma once
#include <iostream>
#include <math.h>
#include "Pipe.h"
#include <thread>

#define SIZE_OF_BOARD 8

using namespace std;

class piece
{
public:
	piece(bool color, string type);
	string getType();
	bool getColor();
	bool getHasMoved();
	void setHasMoved();
	virtual void move(int* position, int* path)  = 0; 

private:
	string _type;
	bool _color;
	bool _hasMoved;
};
