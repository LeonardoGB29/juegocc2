#include "Controller_Item.h"

Controller_Item::Controller_Item(int x, int y, std::unique_ptr<ItemEffect> effect, std::vector<Model_Player*>& players, View_Item& view, Controller_Collision& collision)
    : model(x, y, std::move(effect)), players(players), view(view), collisionI(collision) {}

void Controller_Item::isCollisionWith(Controller_Collision& collision) {

    int currentX = model.getPositionX();
    int currentY = model.getPositionY();

    Model_Player* player1 = players[0];
    Model_Player* player2 = players[1];

    if (collisionI.verificateCollision(collision)) {
        if (collision.getModelCollision().getObjType() == 2) {
            model.applyEffect(*player2);
            model.applyEffect(*player1);
            view.removeImage();
            model.removeModel();
        }
    }
    
    view.spriteSetPosition(model.getPositionX(), model.getPositionY());
    collisionI.UpdatePosition(model.getPositionX(), model.getPositionY());

}