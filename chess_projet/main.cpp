#include <iostream>


#define	STARTING_BOARD "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"
#define SIZE 8

using namespace std;

int main()
{
	int index = 0;
	cout << STARTING_BOARD << endl;

	for (int line = 0; line < SIZE; line++)
	{
		for (int i = 0;i < SIZE; i++)
		{
			cout << STARTING_BOARD[index] << " ";
			index++;
		}
		cout << endl;
	}
	
	return 0;
}
