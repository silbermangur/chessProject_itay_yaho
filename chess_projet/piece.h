#pragma once
#include <iostream>

#define SIZE 8

using namespace std;

class piece
{
public:
	piece(bool color);
	
	virtual int* move(int* position)  = 0; 

private:
	// string _position;
	bool _color;
	bool _hasMoved;
};
