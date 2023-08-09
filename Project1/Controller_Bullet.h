#pragma once
#include "View_Bullet.h"
#include "Model_Bullet.h"
#include "Model_Player.h"
#include "Controller_Player.h"
#include "Controller_Collision.h"

class Controller_Bullet{
private:
    Model_Bullet& bulletModel;
    View_Bullet& bulletView;
    const int screenWidth = 1088;
    const int screenHeight = 640;
    Controller_Collision bulletCollision;
public:
    Controller_Bullet(Model_Bullet&, View_Bullet&);
    void Update();
    //void Move();
    bool isOut();
    View_Bullet& getView() { return bulletView; }
    Controller_Collision& getCollision();
    Model_Bullet& getModel();
};