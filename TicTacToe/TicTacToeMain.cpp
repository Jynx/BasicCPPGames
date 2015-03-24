#include <iostream>

#include "TicTacToe.cpp"

int main()	
{
	char input;
	bool isDone = false;
	TicTacToe game;
	while(!isDone)
	{
		game.PlayGame();
		std::cout<<"Would you like to play again? (Y/N): ";
		std::cin >> input;
		if(input == 'N' || input == 'n')
		{
			isDone = true;
		}
	}


	system("PAUSE");
	return 0;
}