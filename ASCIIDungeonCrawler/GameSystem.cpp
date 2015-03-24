#include "GameSystem.h"
#include <string>
#include <stdio.h>
#include <conio.h>
#include <iostream>

GameSystem::GameSystem(std::string levelFileName) {
	_player.Init(1, 100, 10, 10, 0);
    _level.Load(levelFileName, _player);
    _level.Print();
    system("PAUSE");
}

void GameSystem::RunGame() {
	bool isDone = false;

	while (!isDone) {
		_level.Print();
		PlayerMove();
		_level.UpdateMonsters(_player);
	}
}

void GameSystem::PlayerMove() {
    std::cout << "Enter a move command (wsad): ";
    char input = _getch();
    _level.MovePlayer(input, _player);
}