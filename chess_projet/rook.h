#pragma once
#include "piece.h"


class rook : piece
{
public:
	rook(bool color);
	int* move(int* position) override;
};