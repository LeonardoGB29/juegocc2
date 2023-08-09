#include "Model_Item.h"
#include "Model_ItemEffect.h"

Model_Item::Model_Item(int x, int y, std::unique_ptr<ItemEffect> effect)
    : effect(std::move(effect)) {
    position[0] = x;
    position[1] = y;
}

void Model_Item::applyEffect(Model_Player& player) {
    effect->applyEffect(player);
}

int Model_Item::getPositionX() {
    return position[0];
}

int Model_Item::getPositionY() {
    return position[1];
}

void Model_Item::removeModel() {
    position[0] = 2000;
    position[1] = 2000;
}