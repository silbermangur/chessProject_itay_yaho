#include <iostream>
#include "board.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "knight.h"


using namespace std;

int findIndex(int& x, int& y)
{
	return y * SIZE + x; 
}

int main()
{
	string boardString = STARTING_BOARD;
	board b;
	b.setBoard(boardString);
	b.printBoard();

	while (0 == 0)
	{
		int a[4] = { 0,0,0,0 };
		int* arr;
		// 
		cout << "Enter source index: " << endl;
		cout << "X: ";
		cin >> a[0];
		cout << "Y: ";
		cin >> a[1];
		cout << "Enter destination index: " << endl;
		cout << "X: ";
		cin >> a[2];
		cout << "Y: ";
		cin >> a[3];

		int srcIndex = findIndex(a[0], a[1]);
		int destIndex = findIndex(a[2], a[3]);  

		if (b.getPiece(srcIndex) != nullptr)
		{
			arr = b.getPiece(srcIndex)->move(a); 
			for (int i = 1; i < SIZE; i++)
			{
				if ((arr[i] >= 0 && arr[i] <= 64))
				{
					if ((b.getPiece(arr[i]) == nullptr || ((i < SIZE - 1 && !(arr[i + 1] >= 0 && arr[i + 1] <= 64)) || (i == SIZE))
						&& b.getPiece(arr[i])->getColor() != b.getPiece(srcIndex)->getColor()) && (b.getPiece(srcIndex)->getType()[0] != 'p' 
							|| (abs(arr[0] - arr[1]) % 2 == 0 && b.getPiece(arr[1]) == nullptr && (arr[2] < 0 || arr[2] > 64 || b.getPiece(arr[2]) == nullptr))
							|| (b.getPiece(arr[1]) != nullptr) && arr[0] - arr[1] % 2 != 0))
					{
						continue;
					}
					else
					{
						cout << "Error 2!" << endl;
					}
				}
				else
				{
					break;
				}
			}
			b.playMove(srcIndex, destIndex); // piece array
			// board string
			boardString[destIndex] = boardString[srcIndex];
			boardString[srcIndex] = '#';
		}
		else
		{
			cout << "No piece" << endl;
			exit(1);
		}
		
		b.setBoard(boardString);
		b.printBoard();
	}

	return 0;
}
