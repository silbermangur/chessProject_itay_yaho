#pragma once
#include "piece.h"

class pawn : public piece
{
public:
	pawn(bool color);
	int* move(int* position)override;
};