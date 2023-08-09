#include "Model_Enemy.h"
#include "View_Enemy.h"
#include "Model_Player.h"
#include "Controller_Player.h"
#include "Controller_Enemy.h"
#include <filesystem>

Controller_Enemy::Controller_Enemy(Model_Enemy& model, View_Enemy& view, std::vector<Model_Player*>& players, Controller_Collision& collision)
    : Controller_Character(model, view), model(model), view(view), players(players), collisionE(collision) {}

void Controller_Enemy::Update() { 

    int nearestPlayerX = players[0]->getPositionX();
    int nearestPlayerY = players[0]->getPositionY();

    int minDistance = (nearestPlayerX - model.getPositionX()) * (nearestPlayerX - model.getPositionX()) +
        (nearestPlayerY - model.getPositionY()) * (nearestPlayerY - model.getPositionY());

    for (Model_Player* player : players) {
        int distance = (player->getPositionX() - model.getPositionX()) * (player->getPositionX() - model.getPositionX()) +
            (player->getPositionY() - model.getPositionY()) * (player->getPositionY() - model.getPositionY());
        if (distance < minDistance) {
            nearestPlayerX = player->getPositionX();
            nearestPlayerY = player->getPositionY();
            minDistance = distance;
        }
    }

    int currentX = model.getPositionX();
    int currentY = model.getPositionY();
    int speed = model.getVel();

    if (currentX < nearestPlayerX && currentY < nearestPlayerY)
        model.setPosition(currentX + speed, currentY + speed);
    else if (currentX > nearestPlayerX && currentY > nearestPlayerY)
        model.setPosition(currentX - speed, currentY - speed);
    else if (currentX < nearestPlayerX && currentY > nearestPlayerY)
        model.setPosition(currentX + speed, currentY - speed);
    else if (currentX > nearestPlayerX && currentY < nearestPlayerY)
        model.setPosition(currentX - speed, currentY + speed);
    else if (currentX < nearestPlayerX)
        model.setPosition(currentX + speed, currentY);
    else if (currentX > nearestPlayerX)
        model.setPosition(currentX - speed, currentY);
    else if (currentY < nearestPlayerY)
        model.setPosition(currentX, currentY + speed);
    else if (currentY > nearestPlayerY)
        model.setPosition(currentX, currentY - speed);
    if (model.getHealth()<=0){
        model.setPosition(2000, 2000);
        view.setDirectorySprite(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\collision\\polpo3.png");
    }
    view.spriteSetPosition(model.getPositionX(), model.getPositionY());
    collisionE.UpdatePosition(model.getPositionX(), model.getPositionY());
}
void Controller_Enemy::isCollisionWith(Controller_Collision& collision) {

    int currentX = model.getPositionX();
    int currentY = model.getPositionY();

    int speed = model.getVel();

    if (collisionE.verificateCollision(collision)) {
        //el numero 1 será para objetos solidos
        if (collision.getModelCollision().getObjType() == 3) { //enemigo
            if (currentX < collision.getModelCollision().getPositionx()) {
                model.setPosition(model.getPositionX() - model.getVel() - 1, model.getPositionY());
            }
            if (currentX > collision.getModelCollision().getPositionx()) {
                model.setPosition(model.getPositionX() + model.getVel() + 1, model.getPositionY());
            }
            if (currentY < collision.getModelCollision().getPositiony()) {
                model.setPosition(model.getPositionX(), model.getPositionY() - model.getVel() - 1);
            }
            if (currentY > collision.getModelCollision().getPositiony()) {
                model.setPosition(model.getPositionX(), model.getPositionY() + model.getVel() + 1);
            }
        }
        ///aaaaaaaaaaaaaaaa
        if (collision.getModelCollision().getObjType() == 2) { //jugador

            if (currentX < collision.getModelCollision().getPositionx()) {
                model.setPosition(model.getPositionX() - 3 - 1, model.getPositionY());
            }
            if (currentX > collision.getModelCollision().getPositionx()) {
                model.setPosition(model.getPositionX() + 3 + 1, model.getPositionY());
            }
            if (currentY < collision.getModelCollision().getPositiony()) {
                model.setPosition(model.getPositionX(), model.getPositionY() - 3 - 1);
            }
            if (currentY > collision.getModelCollision().getPositiony()) {
                model.setPosition(model.getPositionX(), model.getPositionY() + 3 + 1);
            }
        }
    }
    view.spriteSetPosition(model.getPositionX(), model.getPositionY());
    collisionE.UpdatePosition(model.getPositionX(), model.getPositionY());
}
void Controller_Enemy::isCollisionWith(Controller_Bullet& collision) {
    if (collisionE.verificateCollision(collision.getCollision())) {
        model.setHealth(model.getHealth() - 25);
        collision.getModel().setPosition(1000, 1000);
    }
}