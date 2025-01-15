#include "queen.h"
#include <iostream>

queen::queen(bool color) : piece(color, "queen")
{

}

queen::queen(bool color, bool isKing) : piece(color, "king")
{
}

void queen::move(int* position, int* path)
{
	for (int i = 0; i < SIZE_OF_BOARD; i++)
	{
		path[i] = -1;
	}

	if ((position[0] == position[2]) ^ (position[1] == position[3]))
	{
		int distance = position[3] - position[1] + position[2] - position[0];
		int postiveMult = distance / abs(distance);
		distance = abs(distance);

		for (int i = 0; i <= distance; i++)
		{//runs on all position in path
			if (position[0] == position[2])
			{
				path[i] = SIZE_OF_BOARD * position[0] + position[1] + (i * postiveMult);
			}
			else
			{
				path[i] = SIZE_OF_BOARD * (position[0] + (i * postiveMult)) + position[1];
			}
			cout << path[i] << endl;
		}
	}
	else if (position[0] - position[2] == position[1] - position[3] && position[0] != position[2])
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
			cout << path[i] << endl;
		}
	}
	else
	{
		cout << "Error! (queen)" << endl;
		throw 6;
	}
}
