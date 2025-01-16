#include "knight.h"

knight::knight(bool color) : piece(color, "knight")
{
}

void knight::move(int* position, int* path)
{
	for (int i = 0; i < SIZE_OF_BOARD; i++)
	{
		path[i] = -1;
	}

	if ((abs(position[0] - position[2]) == 2 && abs(position[1] - position[3]) == 1) || (abs(position[1] - position[3]) == 2 && abs(position[0] - position[2]) == 1))
	{
		path[0] = position[0] + position[1] * SIZE_OF_BOARD;
		path[1] = position[2] + position[3] * SIZE_OF_BOARD;
	}
	else
	{
		throw 6;
	}
}
