#pragma once
#include <vector>
#include "Model_Enemy.h"
#include "View_Enemy.h"
#include "Controller_Player.h"
#include "Model_Player.h"
#include "Controller_Character.h"
#include "Controller_Bullet.h"

class Controller_Enemy : public Controller_Character {
private:
    Model_Enemy& model;
    View_Enemy& view;
    std::vector<Model_Player*>& players;
    Controller_Collision& collisionE;
public:
    Controller_Enemy(Model_Enemy& model, View_Enemy& view, std::vector<Model_Player*>& players, Controller_Collision& collision);
    void Update() override;
    void isCollisionWith(Controller_Collision&);
    void isCollisionWith(Controller_Bullet&);
    Model_Enemy& getModel() { return model; }
    Controller_Collision& getCollision() { return collisionE; }
    void setModel(Model_Enemy& m) { model = m; }
};

class EnemyDecorator : public Controller_Enemy {
private:
    Controller_Enemy* enemy;
public:

    EnemyDecorator(Controller_Enemy* enemy) : Controller_Enemy(*enemy), enemy(enemy) {}
    virtual void Update() override { 
        enemy->Update(); 
    }

};

class SpeedyEnemy : public EnemyDecorator {
public:

    SpeedyEnemy(Controller_Enemy* enemy) : EnemyDecorator(enemy) {
        getModel().setVel(getModel().getVel() * 2);
    }

    void Update() override {
        EnemyDecorator::Update();
    }
};