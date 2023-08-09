#pragma once
#include "View_Character.h"

class View_Player : public View_Character
{
private:
public:
    friend class View_Wrapper;
    View_Player(const std::string);
    View_Player() {}
    void spriteSetPosition(int, int);
    void setDirectorySprite(std::string);
};