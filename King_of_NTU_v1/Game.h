#pragma once
#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "Character.h"

class Game
{
private:
    //Player* players[2];

public:
    Game();
    ~Game();
    void getIDfromUser();
    bool success;
};

#endif