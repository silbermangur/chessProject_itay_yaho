#pragma once
#include "piece.h"

class knight : public piece
{
public:
	knight(bool color);
	void move(int* position, int* path) override;
};