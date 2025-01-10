#pragma once
#include "queen.h"

class king : public queen
{
public:
	king(bool color);
	int* move(int* position) override;
};

