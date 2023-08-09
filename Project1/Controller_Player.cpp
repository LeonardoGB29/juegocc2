#include "Controller_Player.h"
#include "View_Bullet.h"
#include "Model_Bullet.h"
#include <filesystem>
#include "Controller_Bullet.h"

Controller_Player::Controller_Player(Model_Player& model_, View_Player& view_, UserInput& userInput)
    : Controller_Character(model_, view_), model(model_), view(view_), userInput(userInput) {}

void Controller_Player::isCollisionWith(Controller_Collision& CtrlCollision) {
    //es solo para el test de las colisiones
    //se sobrecargará la funcion para las diferentes interaciones con otros objetos
    if (collisionP.verificateCollision(CtrlCollision)) {
        //el numero 1 será para objetos solidos
        if (CtrlCollision.getModelCollision().getObjType() == 1) {
            if (userInput.moveUp) {
                model.setPosition(model.getPositionX(), model.getPositionY() + model.getVely());
                if ((userInput.moveLeft) || (userInput.moveRight)) {
                    if ((model.getPositionX() > CtrlCollision.getModelCollision().getPositionx())) {
                        model.setPosition(model.getPositionX() + model.getVelx(), model.getPositionY());
                    }
                    else {
                        model.setPosition(model.getPositionX() - model.getVelx(), model.getPositionY());
                    }
                }
            }
            if (userInput.moveDown) {
                model.setPosition(model.getPositionX(), model.getPositionY() - model.getVely());
                if ((userInput.moveLeft) || (userInput.moveRight)) {
                    if ((model.getPositionX() > CtrlCollision.getModelCollision().getPositionx())) {
                        model.setPosition(model.getPositionX() + model.getVelx(), model.getPositionY());
                    }
                    else {
                        model.setPosition(model.getPositionX() - model.getVelx(), model.getPositionY());
                    }
                }
            }
            if (userInput.moveLeft) {
                model.setPosition(model.getPositionX() + model.getVelx() + 1, model.getPositionY());
            }
            if (userInput.moveRight) {
                model.setPosition(model.getPositionX() - model.getVelx() - 1, model.getPositionY());
            }
        }
        view.setDirectorySprite(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\collision\\1.png");
    }
    else {
        view.setDirectorySprite(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\collision\\1.png"); //la gracia seria ponerlo todo en un 
        //tileset y llamar solo a las posiciones de los tiles
    }
}

int Controller_Player::getCurrentDirection() {
    if (userInput.shootUp) return 0;
    if (userInput.shootDown) return 1;
    if (userInput.shootLeft) return 2;
    if (userInput.shootRight) return 3;
}

void Controller_Player::Update() {

    if (userInput.moveUp) model.setPosition(model.getPositionX(), model.getPositionY() - model.getVely());
    if (userInput.moveDown) model.setPosition(model.getPositionX(), model.getPositionY() + model.getVely());
    if (userInput.moveLeft) model.setPosition(model.getPositionX() - model.getVelx(), model.getPositionY());
    if (userInput.moveRight) model.setPosition(model.getPositionX() + model.getVelx(), model.getPositionY());

    if (userInput.shoot) {
        int posX = model.getPositionX();
        int posY = model.getPositionY();
        int direction = getCurrentDirection();

        Model_Bullet* newBullet = new Model_Bullet(posX, posY, model.getBulletVel(), direction);
        View_Bullet* newBulletView = new View_Bullet(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\collision\\bullet.png");
        Controller_Bullet* newBulletController = new Controller_Bullet(*newBullet, *newBulletView);

        bullets.push_back(newBulletController);

        userInput.shoot = false;
    }

    auto bullet = bullets.begin();
    while (bullet != bullets.end()) {
        (*bullet)->Update();
        if ((*bullet)->isOut()) {
            delete* bullet;
            bullet = bullets.erase(bullet);
        }
        else {
            ++bullet;
        }
    }

    model.setVely(model.getVel());
    model.setVelx(model.getVel());

    view.spriteSetPosition(model.getPositionX(), model.getPositionY());
    collisionP.UpdatePosition(model.getPositionX(), model.getPositionY());
}

Controller_Collision& Controller_Player::getControllerCollision() {
    return collisionP;
}
Model_Player& Controller_Player::getPlayerModel() {
    return model;
}
void Controller_Player::setControllerParameter(int radius) {
    collisionP = Controller_Collision(0, 0, 0, radius);
}
