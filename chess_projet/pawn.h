#pragma once
#include "piece.h"

class pawn : public piece
{
public:
	pawn(bool color);
	void move(int* position, int* path) override;
};