#pragma once
#include <vector>

class Model_Character {
private:
    int health;
    int position[2];
    int radio;
    int vel;

public:
    Model_Character(int health, float x, float y, int vel, int radio);
    void setHealth(int health);
    int getHealth();
    float getPositionX();
    float getPositionY();
    int getVel();
    void setVel(int);
    void setPosition(int x, int y);
    int getRadius();
    void setRadius(int radio);
};