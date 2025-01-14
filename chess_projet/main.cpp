#include <iostream>
#include "board.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "knight.h"
#include "Pipe.h"
#include <thread>


using namespace std;

int findIndex(int x, int y)
{
	return (SIZE_OF_BOARD - 1 - y) * SIZE_OF_BOARD + x; 
}

int* convertInputToNumbers(string msg)
{
	int arr2[4] = {0,0,0,0};

	arr2[0] = msg[0] - 'a';
	arr2[1] = msg[1] - '1';
	arr2[2] = msg[2] - 'a';
	arr2[3] = msg[3] - '1';

	return arr2;
}

int main()
{
	srand(time_t(NULL));
	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return 0;
		}
	}

	char msgToGraphics[1024];
	char boardString[] = STARTING_BOARD;
	board b;
	b.setBoard(boardString);
	b.printBoard();



		strcpy_s(msgToGraphics, boardString);
		p.sendMessageToGraphics(msgToGraphics);   // send the board string

		// get message from graphics
		string msgFromGraphics = p.getMessageFromGraphics();


		while (msgFromGraphics != "quit")
		{
			// should handle the string the sent from graphics
			// according the protocol. Ex: e2e4           (move e2 to e4)

			// YOUR CODE
			int* a = convertInputToNumbers(msgFromGraphics);
			int srcIndex = findIndex(a[0], a[1]);
			int destIndex = findIndex(a[2], a[3]);
			int* arr;
			// 

			

			if (b.getPiece(srcIndex) != nullptr)
			{
				arr = b.getPiece(srcIndex)->move(a);
				for (int i = 1; i < SIZE_OF_BOARD; i++)
				{
					if ((arr[i] >= 0 && arr[i] <= 64))
					{
						if ((b.getPiece(arr[i]) == nullptr || ((i < SIZE_OF_BOARD - 1 && !(arr[i + 1] >= 0 && arr[i + 1] <= 64)) || (i == SIZE_OF_BOARD))
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

			strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation

			/******* JUST FOR EREZ DEBUGGING ******/
			int r = rand() % 10; // just for debugging......
			msgToGraphics[0] = (char)(1 + '0');
			msgToGraphics[1] = 0;
			/******* JUST FOR EREZ DEBUGGING ******/


			// return result to graphics		
			p.sendMessageToGraphics(msgToGraphics);

			// get message from graphics
			msgFromGraphics = p.getMessageFromGraphics();
		}

	p.close();
	return 0;
}
