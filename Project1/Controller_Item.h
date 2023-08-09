#pragma once
#include "View_Item.h"
#include "Model_Item.h"
#include "Model_Player.h"
#include "Controller_Collision.h"

class Controller_Item {
private:
    Model_Item model;
    View_Item& view;
    Controller_Collision& collisionI;
    std::vector<Model_Player*>& players;
public:
    //item(x,y,tipo de efecto, vecto de modelos,collision)
    Controller_Item(int x, int y, std::unique_ptr<ItemEffect> effect, std::vector<Model_Player*>& players, View_Item& view, Controller_Collision& collision);
    void isCollisionWith(Controller_Collision& collision);
};