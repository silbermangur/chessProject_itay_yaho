#include "rook.h"
#include <iostream>
#include <math.h>

rook::rook(bool color) : piece(color, "rook")
{
	
}

void rook::move(int* position, int* path)
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
				if (!(position[0] == position[2]))
				{
					path[i] = SIZE_OF_BOARD * position[1] + position[0] + (i * postiveMult);
				}
				else 
				{
					path[i] = SIZE_OF_BOARD * (position[1] + (i * postiveMult)) + position[0];
				}
			}
	}
	else
	{
		// if not - return  error
		cout << "Error! (rook)" << endl;
		throw 6;
	}
}
