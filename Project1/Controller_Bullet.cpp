#include <iostream>
#include<filesystem>

#include "Controller_Bullet.h"
#include "View_Bullet.h"
#include "Model_Bullet.h"
#include "Model_Player.h"
#include "Controller_Player.h"
#include "View_Sprite.h"
#include "View_Wrapper.h"

Controller_Bullet::Controller_Bullet(Model_Bullet& model, View_Bullet& view)
    : bulletModel(model), bulletView(view) {
    bulletCollision.getModelCollision().setRadius(3);
    bulletCollision.getModelCollision().setObjType(5);
}

void Controller_Bullet::Update() {
    int dic = bulletModel.getDirection();

    float posX = bulletModel.getPosX();
    float posY = bulletModel.getPosY();

    if (dic == 0)
        bulletModel.setPosition(posX, posY - bulletModel.getVel());
    else if (dic == 1)
        bulletModel.setPosition(posX, posY + bulletModel.getVel());
    else if (dic == 2)
        bulletModel.setPosition(posX - bulletModel.getVel(), posY);
    else if (dic == 3)
        bulletModel.setPosition(posX + bulletModel.getVel(), posY);

    bulletCollision.UpdatePosition(bulletModel.getPosX(), bulletModel.getPosY());
    bulletView.spriteSetPosition(bulletModel.getPosX(), bulletModel.getPosY());
}


bool Controller_Bullet::isOut() {
    int x = bulletModel.getPosX();
    int y = bulletModel.getPosY();

    if (x < 0 || x > screenWidth || y < 0 || y > screenHeight) return true;
    else return false;
}
Controller_Collision& Controller_Bullet::getCollision() {
    return bulletCollision;
}
Model_Bullet& Controller_Bullet::getModel() {
    return bulletModel;
}