#pragma once
#include "piece.h"

class bishop : public piece
{
public:
	bishop(bool color);
	int* move(int* position) override;
};