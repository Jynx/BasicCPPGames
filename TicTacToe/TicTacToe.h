#pragma once

class TicTacToe
{
public:
	TicTacToe();

	void PlayGame();
private:
	int GetXCoord();
	int GetYCoord();
	bool PlaceMarker(int& x, int& y, char& currPlayer);
	bool CheckForVictory(char& currPlayer);
	void ClearBoard();
	void PrintBoard();
	char board[3][3];

};