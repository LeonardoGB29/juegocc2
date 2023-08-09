#pragma once
#include "View_Character.h"
#include "View_Sprite.h"

class View_Enemy : public View_Character {
public:
    friend class View_Wrapper;
    View_Enemy() {}
    View_Enemy(const std::string);
    void spriteSetPosition(int, int);
    void setDirectorySprite(std::string);
};