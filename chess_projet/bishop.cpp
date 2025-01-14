#include "bishop.h"
#include <iostream>
#include <math.h>

bishop::bishop(bool color) : piece(color, "bishop")
{

}

int* bishop::move(int* position)
{
	int path[SIZE_OF_BOARD] = {};
	for (int i = 0; i < SIZE_OF_BOARD; i++)
	{
		path[i] = -1;
	}

	if (position[0] - position[2] == position[1] - position[3]  && position[0] != position[2])
	{
		int step = -9;
		
		if (position[0] < position[2]) 
		{
			step += 2;
		}
		if (position[1] < position[3])
		{
			step += 16;
		}
		for (int i = 0; i <= abs(position[0] - position[2]); i++)
		{
			path[i] = position[0] + position[1] * SIZE_OF_BOARD + step * i;
		}
	}

	return path;

}
