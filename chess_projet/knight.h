#pragma once
#include "piece.h"

class knight : public piece
{
public:
	knight(bool color);
	int* move(int* position) override;
};