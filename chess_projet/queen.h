#pragma once
#include "piece.h"

class queen : piece
{
public:
	queen(bool color);
	int* move(int* position) override;
};
