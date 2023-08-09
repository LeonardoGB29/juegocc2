#pragma once
#include "Model_Player.h"
#include "Model_Enemy.h"

class Model_Game {
public:
    Model_Player modelPlayer;
    Model_Player modelPlayer2;
    Model_Enemy modelEnemy;
    Model_Enemy modelEnemy2;

    Model_Game();
};
