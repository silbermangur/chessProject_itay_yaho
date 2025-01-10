#pragma once
#include "piece.h"


class rook : public piece
{
public:
	rook(bool color);
	int* move(int* position) override;
};