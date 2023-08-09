#pragma once
#include "Model_Player.h"

class Model_Player;

class ItemEffect {
public:
    virtual ~ItemEffect() {}
    virtual void applyEffect(Model_Player& player) = 0;
};

class SpeedBoostEffect : public ItemEffect {
public:
    void applyEffect(Model_Player& player) override;
};

class HealthBoostEffect : public ItemEffect {
public:
    void applyEffect(Model_Player& player) override; // Declaration only
};