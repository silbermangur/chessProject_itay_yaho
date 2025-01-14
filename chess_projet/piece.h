#pragma once
#include <iostream>
#include <math.h>

#define SIZE 8

using namespace std;

class piece
{
public:
	piece(bool color, string type);
	string getType();
	bool getColor();
	bool getHasMoved();
	void setHasMoved();
	virtual int* move(int* position)  = 0; 

private:
	string _type;
	bool _color;
	bool _hasMoved;
};
