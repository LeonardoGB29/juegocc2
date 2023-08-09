#pragma once
#include "Model_Bullet.h"
#include "Controller_Bullet.h"
#include "View_Bullet.h"

class Bullet {
private:
    Model_Bullet model;
    View_Bullet view;
    Controller_Bullet controller;

public:
    Bullet(Model_Character& player, UserInput&, View_Bullet& view, int speed);
    void Update();
    View_Bullet& getView();
};
