#include "Monster.h"
#include <string>
#include <random>
#include <ctime>
#include <iostream>
#include <stdio.h>

Monster::Monster(std::string name, char tile, int level, int attack,
                 int defense, int health, int exp) {
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_experienceValue = exp;
}

void Monster::SetPosition(int x, int y)
{
	_x = x;
	_y = y;

}

void Monster::GetPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}

int Monster::Attack() {
	static std::default_random_engine randomEngine(time(NULL));
	std::uniform_int_distribution<int> attackRoll(0, _attack);
	return attackRoll(randomEngine);
}

int Monster::TakeDamage(int attack) {
    attack -= _defense;
    if (attack > 0) {
    	_health -= attack;
    	if (_health <= 0) {
    		return _experienceValue;
    	}
    } 
    return 0;
}

char Monster::GetMove(int playerX, int playerY) {
	static std::default_random_engine randomEngine(time(NULL));
	std::uniform_int_distribution<int> moveRoll(0, 6);

	int distanceFromPlayer;
	int dx = _x - playerX;
	int dy = _y - playerY;
	int adx = abs(dx);
	int ady = abs(dy);

	distanceFromPlayer = adx + ady;

	if (distanceFromPlayer <= 5) {
		if(adx < ady) {
			if (dx > 0) {
				return 'a';
			}
		} else {
			return 'd';
		}

		if(ady < adx) {
			if (dy > 0) {
				return 'w';
			}
		} else {
			return 's';
		}
	}
	int randomMove = moveRoll(randomEngine);
	switch (randomMove) {
		case 0:
			return 'a';
		case 1:
			return 'w';
		case 2: 
			return 's';
		case 3:
			return 'd';
		default:
			return '.';
	}
}