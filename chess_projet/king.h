#pragma once
#include "queen.h"

class king : queen
{
public:
	king(bool color);
	int* move(int* position) override;
};

