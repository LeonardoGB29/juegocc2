#pragma once
#include "Model_Character.h"
#include "View_Wrapper.h"

class Model_Bullet {
private:
    float x, y;
    int vel;
    int dic;
public:
    Model_Bullet(float x, float y, int vel, int initialDirection);
    float getPosX() const;
    float getPosY() const;
    int getVel() const;
    void setPosition(float,float);
    int getDirection() const;
    void setDirection(int);
};