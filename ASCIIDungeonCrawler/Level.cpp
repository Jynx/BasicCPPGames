#include "Level.h"
#include <fstream>
#include <string>
#include <iostream>


Level::Level() {}

void Level::Load(std::string fileName, Player &player) {
    std::fstream file;
    file.open(fileName);
    if (file.fail()) {
        perror(fileName.c_str());
        exit(1);
        system("PAUSE");
    }
    std::string line;
    while (getline(file, line)) {
        _levelData.push_back(line);
    }
    file.close();
    for (int i = 0; i < _levelData.size(); i++) {
        for (int j = 0; j < _levelData[i].size(); j++) {
            char tile = _levelData[i][j];
            switch (tile) {
                case '@': // player
                    player.SetPosition(j, i);
                    break;
                case 'S': // snake
                	_monsters.push_back(Monster("Snake", tile, 1, 3, 1, 10, 50));
                	_monsters.back().SetPosition(j,i);
                	break;
                case 'G': // giant
                	_monsters.push_back(Monster("Goblin", tile, 2, 10, 5, 35, 150));
           			_monsters.back().SetPosition(j,i);
                	break;
                case 'O': // ogre
                	_monsters.push_back(Monster("Ogre", tile, 4, 20, 40, 200, 500));
					_monsters.back().SetPosition(j,i);
                	break;
                case 'D': // DRAGON!
                	_monsters.push_back(Monster("Dragon", tile, 100, 2000, 2000, 2000, 50000000));
                	_monsters.back().SetPosition(j,i);
                	break;
                case 'B': // bandit
                	_monsters.push_back(Monster("Bandit", tile, 3, 15, 10, 100, 250));
                	_monsters.back().SetPosition(j,i);
            	case 'V':
            		_monsters.push_back(Monster("VOLOCOCK", tile, 4, 20, 20, 200, 500));
            		_monsters.back().SetPosition(j,i);
            		break;
            }
        }
    }
}

void Level::Print() {
    std::cout << std::string(100, '\n');
    for (int i = 0; i < _levelData.size(); i++) {
        printf("%s\n", _levelData[i].c_str());
    }
    printf("\n");
}

void Level::MovePlayer(char input, Player &player) {
    int playerX, playerY;
    char moveTile;
    player.GetPosition(playerX, playerY);
    switch (input) {
        case 'w':
        case 'W':
            ProcessTile(player, playerX, playerY - 1);
            break;
        case 's':
        case 'S':
            ProcessTile(player, playerX, playerY + 1);
            break;
        case 'a':
        case 'A':
            ProcessTile(player, playerX - 1, playerY);

            break;
        case 'd':
        case 'D':
            ProcessTile(player, playerX + 1, playerY);
            break;
        default:
            printf("INVALID INPUT\n");
            system("PAUSE");
    }
}

char Level::GetTile(int x, int y) {
    char tile;
    return tile = _levelData[y][x];
}

void Level::SetTile(int x, int y, char tile) { _levelData[y][x] = tile; }

void Level::ProcessTile(Player &player, int targX, int targY) {
    int playerX, playerY;
    player.GetPosition(playerX, playerY);
    char tile = GetTile(targX, targY);
    switch (tile) {
        case '.':
            player.SetPosition(targX, targY);
            SetTile(playerX, playerY, '.');
            SetTile(targX, targY, '@');
            break;
        case '#':
        	break;
        default:
        	BattleMonster(player, targX, targY);
        	break;
    }
}

void Level::ProcessMonsterTile(Player &player, int monsterIndex, int targX,
                               int targY) {
    int playerX, playerY;
    int monsterX, monsterY;

    _monsters[monsterIndex].GetPosition(monsterX, monsterY);
    player.GetPosition(playerX, playerY);
    char tile = GetTile(targX, targY);
    switch (tile) {
        case '.':
            _monsters[monsterIndex].SetPosition(targX, targY);
            SetTile(monsterX, monsterY, '.');
            SetTile(targX, targY, _monsters[monsterIndex].GetTile());
            break;
        case '#':
            break;
        default:
            break;
    }
}

void Level::BattleMonster(Player &player, int targX, int targY) {
	int monsterX, monsterY, attackRoll, attackResult;
	int playerX, playerY;
	std::string enemyName;

	player.GetPosition(playerX, playerY);
	for(int i = 0; i < _monsters.size(); i++) {
		_monsters[i].GetPosition(monsterX, monsterY);
		enemyName = _monsters[i].GetName();
		if(targX == monsterX && targY == monsterY) {
			//battle.
			attackRoll = player.Attack();
			printf("Player swung for: %d damage against %s\n", attackRoll, enemyName.c_str());
			attackResult = _monsters[i].TakeDamage(attackRoll);
			if (attackResult != 0) {
				SetTile(targX, targY, '.');
				Print();
				printf("Monster Died!\n");
				system("PAUSE");
				player.AddExperience(attackResult);
				_monsters[i] = _monsters.back();
				_monsters.pop_back();
				i--;
				
				return;
			} 
			attackRoll = _monsters[i].Attack();
			printf("%s attacked player for: %d damage!\n", enemyName.c_str(), attackRoll);
			attackResult = player.TakeDamage(attackRoll);
			if(attackResult == 1) {
				SetTile(playerX, playerY, 'X');
				Print();
				printf("You died!!\n");
				system("PAUSE");
				exit(0);
			}
			system("PAUSE");
			return;
		}
	}
}

void Level::UpdateMonsters(Player &player) {
	char aiMove;
	int playerX;
	int playerY;
	int monsterX, monsterY;
	player.GetPosition(playerX, playerY);
	for (int i = 0; i < _monsters.size(); i++) {
		aiMove = _monsters[i].GetMove(playerX, playerY);
		_monsters[i].GetPosition(monsterX, monsterY);
		switch (aiMove) {
        case 'w':
            ProcessMonsterTile(player, i, monsterX, monsterY - 1);
            break;
        case 's':
            ProcessMonsterTile(player, i, monsterX, monsterY + 1);
            break;
        case 'a':
            ProcessMonsterTile(player, i, monsterX - 1, monsterY);

            break;
        case 'd':
            ProcessMonsterTile(player, i, monsterX + 1, monsterY);
            break;
    	}
	}
}