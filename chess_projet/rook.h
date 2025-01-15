#pragma once
#include "piece.h"


class rook : public piece
{
public:
	rook(bool color);
	void move(int* position, int* path) override;
};