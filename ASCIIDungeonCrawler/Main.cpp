#include <stdio.h>
#include <conio.h>
#include <iostream>

#include "GameSystem.h"

int main() {
    GameSystem gameSystem("W:\\resumeTests\\AsciiRogueLike\\level1.txt");
    gameSystem.RunGame();
    return 0;
}