#pragma once
#include "Model_ItemEffect.h"
#include <memory>

class Model_Item {
private:
    int position[2];
public:
    std::unique_ptr<ItemEffect> effect;
    Model_Item(int x, int y, std::unique_ptr<ItemEffect> effect);
    void applyEffect(Model_Player& player);
    int getPositionX();
    int getPositionY(); 
    void removeModel();
};