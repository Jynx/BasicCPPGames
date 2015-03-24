#ifndef _LEVEL_
#define _LEVEL_

#include <vector>
#include <string>
#include "Player.h"
#include "Monster.h"

class Level {
public:
    Level();
    void Load(std::string fileName, Player &player);
    void Print();
    void MovePlayer(char input, Player &player);
    char GetTile(int x, int y);
    void SetTile(int x, int y, char tile);
    void UpdateMonsters(Player &player);

private:
    void ProcessTile(Player &player, int targX, int targY);
    void ProcessMonsterTile(Player &player, int monsterIndex, int targX,
                            int targY);
    void BattleMonster(Player &player, int targX, int targY);

private:
    std::vector<Monster> _monsters;
    std::vector<std::string> _levelData;
};

#endif