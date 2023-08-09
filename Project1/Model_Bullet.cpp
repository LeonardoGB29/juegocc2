#include "Model_Bullet.h"
#include <iostream>
Model_Bullet::Model_Bullet(float x, float y, int vel, int initialDirection) :
    x(x), y(y), vel(vel), dic(initialDirection) {}

float Model_Bullet::getPosX() const {
    return x; 
}

float Model_Bullet::getPosY() const {
    return y; 
}

int Model_Bullet::getVel() const {
    return vel;
}

void Model_Bullet::setPosition(float x_, float y_)  {
    x = x_;
    y = y_;
}

int Model_Bullet::getDirection() const {
    return dic;
}

void Model_Bullet::setDirection(int newDic) {
    dic = newDic;
}