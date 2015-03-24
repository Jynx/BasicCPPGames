#ifndef _GAMESYSTEM_
#define _GAMESYSTEM_

#include "Level.h"
#include "Player.h"
#include <string>
#include <vector>

class GameSystem {
public:
    GameSystem(std::string levelFileName);
    void RunGame();
    void PlayerMove();

private:
    Level _level;
    Player _player;
};

#endif

