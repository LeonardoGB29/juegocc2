#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "View_Character.h"

class View_Bullet : public View_Sprite {

public:
    View_Bullet(const std::string&);
    void spriteSetPosition(int, int);
    void setDirectorySprite(const std::string&);
};