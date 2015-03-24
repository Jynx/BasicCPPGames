#ifndef _PLAYER_
#define _PLAYER_

class Player {
public:
    Player();
    void Init(int level, int health, int attack, int defense, int experience);
    void SetPosition(int x, int y);
    void GetPosition(int &x, int &y);
    void AddExperience(int experience);
    int Attack();
    int TakeDamage(int attack);

private:
    int _level;
    int _health;
    int _attack;
    int _defense;
    int _experience;
    int _x, _y;
};

#endif