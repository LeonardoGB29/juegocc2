#pragma once
#include <string>
#include <vector>
#include "Model_Character.h"

class Model_Player : public Model_Character {
private:
    int velx = 0;
    int vely = 0;
    int bulletVel;
    int health;
public:

    Model_Player(int health, float x, float y, int vel, int radio, int bulletVel);
    int getVelx();
    int getVely();
    void setVelx(int);
    void setVely(int);
    int getBulletVel();
    void setBulletVel(int);
    int getHealth();
    void setHealth(int);
};