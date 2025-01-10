#pragma once
#include "piece.h"

class queen : public piece
{
public:
	queen(bool color);
	int* move(int* position) override;
};
