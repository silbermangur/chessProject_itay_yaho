#include "rook.h"
#include <iostream>
#include <math.h>

rook::rook(bool color) : piece(color, "rook")
{
	
}

int* rook::move(int* position)
{
	int path[SIZE_OF_BOARD] = {};
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
			}
	}
	else
	{
		// if not - return  error
		cout << "Error!" << endl;
	}
	

	return path;
}
