#pragma once
#include "queen.h"

class king : public queen
{
public:
	king(bool color);
	void move(int* position, int* path) override;
};

