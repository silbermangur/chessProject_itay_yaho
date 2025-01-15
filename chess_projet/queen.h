#pragma once
#include "piece.h"

class queen : public piece
{
public:
	queen(bool color);
	queen(bool color, bool isKing);
	void move(int* position, int* path) override;

};
