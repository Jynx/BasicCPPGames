#include "Player.h"
#include <random>
#include <ctime>
#include <stdio.h>

Player::Player() { _x = _y = 0; }

void Player::Init(int level, int health, int attack, int defense,
                  int experience) {
    _level = level;
    _health = health;
    _attack = attack;
    _defense = defense;
    _experience = experience;
}

void Player::SetPosition(int x, int y) {
    _x = x;
    _y = y;
}

void Player::GetPosition(int &x, int &y) {
    x = _x;
    y = _y;
}

void Player::AddExperience(int experience) {
    _experience += experience;
    while (_experience > 50) {
        printf("Leveled up!\n");
        _experience -= 50;
        _attack += 10;
        _defense += 5;
        _health += 10;
        _level++;
        system("PAUSE");
    }
}

int Player::Attack() {
    static std::default_random_engine randomEngine(time(NULL));
    std::uniform_int_distribution<int> attackRoll(0, _attack);
    return attackRoll(randomEngine);
}

int Player::TakeDamage(int attack) {
    attack -= _defense;
    if (attack > 0) {
        _health -= attack;
        if (_health <= 0) {
            return 1;
        }
    }
    return 0;
}