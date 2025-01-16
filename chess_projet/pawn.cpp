#include "pawn.h"

pawn::pawn(bool color) : piece(color, "pawn")
{
}

void pawn::move(int* position, int* path)
{
	for (int i = 0; i < SIZE_OF_BOARD; i++)
	{
		path[i] = -1;
	}
	int color = -1;
	if ((this->getColor()))
	{
		color = 1;
	}
	//    X
	if (((position[1] + color) == position[3]) || (position[1] + color * 2 == position[3]  && position[0] == position[2]  && !this->getHasMoved()) && (position[0] == position[2] || position[0] == position[2] + 1 || position[0] == position[2] - 1))
	{//   Y
		path[0] = position[0] + position[1] * SIZE_OF_BOARD;
		if (position[1]  + color * 2 == position[3])
		{
			path[1] = position[0] + (position[1] + color) * SIZE_OF_BOARD;
			path[2] = position[2] + position[3] * SIZE_OF_BOARD;
		}
		else
		{
			path[1] = position[2] + position[3] * SIZE_OF_BOARD;
		}
	}
	else
	{
		throw 6;
	}
	this->setHasMoved();
}
