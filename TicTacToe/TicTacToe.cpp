#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe()
{
	ClearBoard();
}

void TicTacToe::PlayGame()
{
	char player1 = 'X';
	char player2 = 'O';
	char currPlayer = player1;

	bool isDone = false;	
	int x, y;
	int turnCount = 0;

	while(!isDone)
	{
		PrintBoard();
		x = GetXCoord();
		y = GetYCoord();
		if(!PlaceMarker(x, y, currPlayer))
		{
			std::cout<<"Spot is occupied!\n";
		}
		else
		{	
			turnCount++;	
			if(CheckForVictory(currPlayer))
			{
				std::cout<< "The game is over!! Player: " << currPlayer << " has won!\n";
				isDone = true;
			}
			else if (turnCount == 9)
			{
				std::cout << "The Game is over and ended in a tie!\n";
				isDone = true;
			}
			if(currPlayer == player1)
			{
				currPlayer = player2;
			}
			else
			{
				currPlayer = player1;
			}
		}
	}
}

int TicTacToe::GetXCoord()
{
	bool isInputBad = true;
	int x;
	while(isInputBad)
	{
		std::cout<< "Enter the X Coordinate: ";
		std::cin >> x;	

		if(x < 1 || x > 3)
		{
			std::cout<< "Invalid Coordinate!\n";
		}
		else
		{
			isInputBad = false;
		}
	}
	return x -1;
}

int TicTacToe::GetYCoord()
{
	bool isInputBad = true;
	int y;
	while(isInputBad)
	{
		std::cout<< "Enter the Y Coordinate: ";
		std::cin >> y;	

		if(y < 1 || y > 3)
		{
			std::cout<< "Invalid Coordinate!\n";
		}
		else
		{
			isInputBad = false;
		}
	}
	return y - 1;
}

bool TicTacToe::PlaceMarker(int& x, int& y, char& currPlayer)
{
	if(board[x][y] != ' ')
	{
		return false;
	}

	board[x][y]	 = currPlayer;
	return true;
}

bool TicTacToe::CheckForVictory(char& currPlayer)
{
	for(int i = 0; i < 3; i ++)
	{
		if((board[i][0] == currPlayer) && (board[i][0] == board[i][1] && board[i][1] == board[i][2]))
		{
			return true;
		}
 	}

 	for(int i = 0; i < 3; i++)
 	{
 		if( (board[i][0] == currPlayer) && (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
		{
			return true;
		}
 	}

 	if((board[0][0] == currPlayer) && (board[0][0] == board[1][1] && board[1][1] == board[2][2]))
	{
		return true;
	}

	if((board[2][0] == currPlayer) &&(board[0][2] == board[1][1] && board[1][1] == board[2][0]))
	{
		return true;
	}

	return false;
}

void TicTacToe::ClearBoard()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void TicTacToe::PrintBoard()
{
	std::cout << std::endl;
	std::cout << " |1 2 3|\n";
	for(int i =0; i < 3; i++)
	{
		std::cout<< " -------\n";
		std::cout<< i+1 <<"|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
	}
	std::cout<< " -------\n";
}