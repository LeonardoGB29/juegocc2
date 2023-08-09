#pragma once
#include "Model_Character.h"
#include "View_Character.h"

class Controller_Character {
private:
    Model_Character& model;
    View_Character& view;

public:
    Controller_Character(Model_Character& model, View_Character& view);
    virtual void Update() = 0;
};
