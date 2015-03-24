#ifndef _MONSTER_
#define _MONSTER_

#include <string>

class Monster {
public:
    Monster(std::string name, char tile, int level, int attack, int defense,
            int health, int exp);
    void SetPosition(int x, int y);
    void GetPosition(int &x, int &y);
    int Monster::Attack();
    int TakeDamage(int attack);
    std::string GetName(){ return _name;}
    char GetMove(int playerX, int playerY);
    char GetTile(){return _tile;}


private:
    std::string _name;
    int _x, _y;
    char _tile;
    int _attack;
    int _defense;
    int _health;
    int _experienceValue;
    int _level;
};

#endif