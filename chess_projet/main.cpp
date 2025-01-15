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

void convertInputToNumbers(string msg, int* a)
{
	a[0] = msg[0] - 'a';
	a[1] = msg[1] - '1';
	a[2] = msg[2] - 'a';
	a[3] = msg[3] - '1';
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
	bool turn = false;
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
			cout << "turn: " << b.getTurn() << endl;
			// should handle the string the sent from graphics
			// according the protocol. Ex: e2e4           (move e2 to e4)

			int src[2] = {};
			int dest[2] = {};
			int a[4] = {};
			convertInputToNumbers(msgFromGraphics, a);
			src[0] = a[0], src[1] = a[1], dest[0] = a[2], dest[1] = a[3];
			int srcIndex = findIndex(src[0], src[1]); 
			int destIndex = findIndex(dest[0], dest[1]);
			int srcIndex2 = ((SIZE_OF_BOARD - (srcIndex / SIZE_OF_BOARD) - 1) * SIZE_OF_BOARD + srcIndex % SIZE_OF_BOARD); 
			int destIndex2 = ((SIZE_OF_BOARD - (destIndex / SIZE_OF_BOARD) - 1)* SIZE_OF_BOARD + destIndex % SIZE_OF_BOARD);
			int arr[SIZE_OF_BOARD] = {-1, -1, -1, -1, -1, -1, -1, -1};
			
			if (b.getPiece(srcIndex2) != nullptr)
			{
				if (b.getPiece(srcIndex2)->getColor() == turn)
				{
					msgToGraphics[0] = (char)(2 + '0');
					msgToGraphics[1] = 0;

					// return result to graphics		
					p.sendMessageToGraphics(msgToGraphics);
					// get message from graphics
					msgFromGraphics = p.getMessageFromGraphics();
					continue;
				}

				if (b.getPiece(srcIndex2) != nullptr)
				{
					try
					{
						b.getPiece(srcIndex2)->move(a, arr);
						for (int i = 1; i < SIZE_OF_BOARD; i++)
						{
							if ((arr[i] >= 0 && arr[i] <= 64))
							{
								bool flag = false;
								if (b.getPiece(arr[i]) == nullptr)
								{
									if (b.getPiece(srcIndex2)->getType() == "pawn")
									{
										if ((arr[0] - arr[1]) % 2 != 0)
										{
											flag = true;
										}
									}
								}
								else
								{
									if (i == SIZE_OF_BOARD || arr[i + 1] == NULL)
									{
										if (b.getPiece(srcIndex2)->getColor() == b.getPiece(destIndex2)->getColor())
										{
											throw 3;
										}
										else
										{
											if (b.getPiece(srcIndex2)->getType() == "pawn")
											{
												if ((arr[0] - arr[1]) % 2 == 0)
												{
													flag = true;
												}
											}
										}
									}
									else
									{
										throw 6;
									}
								}
								if (flag)
								{
									cout << "Error 2!" << endl;
									throw 6;
								}
							}
							else
							{
								break;
							}
						}
						b.playMove(srcIndex2, destIndex2); // piece array
						// board string
						boardString[destIndex] = boardString[srcIndex];
						boardString[srcIndex] = '#';
						throw 0;
					}
					catch (int e)
					{
						if (e == 0 || e == 1)
						{
							b.setTurn(turn);
						}
						msgToGraphics[0] = '0' + e;
						msgToGraphics[1] = 0;

						// return result to graphics		
						p.sendMessageToGraphics(msgToGraphics);
						// get message from graphics
						msgFromGraphics = p.getMessageFromGraphics();
					}
				}
				else
				{
					cout << "No piece" << endl;
					exit(1);
				}
			}
			else
			{
				msgToGraphics[0] = '0' + 2;
				msgToGraphics[1] = 0;

				// return result to graphics		
				p.sendMessageToGraphics(msgToGraphics);
				// get message from graphics
				msgFromGraphics = p.getMessageFromGraphics();
			}

			b.setBoard(boardString);
			b.printBoard();
						
		}

	p.close();
	return 0;
}
