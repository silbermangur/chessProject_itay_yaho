#pragma once
#include "piece.h"

class bishop : piece
{
public:
	bishop(bool color);
	int* move(int* position) override;
};