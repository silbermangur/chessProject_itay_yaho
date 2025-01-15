#pragma once
#include "piece.h"

class bishop : public piece
{
public:
	bishop(bool color);
	void move(int* position, int* path) override;
};