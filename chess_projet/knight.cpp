#include "knight.h"

knight::knight(bool color) : piece(color)
{
}

int* knight::move(int* position)
{
	int path[SIZE] = {};
	for (int i = 0; i < SIZE; i++)
	{
		path[i] = -1;
	}

	if ((abs(position[0] - position[2]) == 2 && abs(position[1] - position[3]) == 1) || (abs(position[1] - position[3]) == 2 && abs(position[0] - position[2]) == 1))
	{
		path[0] = position[0] + position[1] * SIZE;
		path[1] = position[2] + position[3] * SIZE; 
	}
	else
	{
		cout << "Error!" << endl;
	}
	

	return path;
}
