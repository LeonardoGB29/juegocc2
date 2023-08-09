#pragma once
#include <SFML/Graphics.hpp>
#include "View_Sprite.h"

class View_Character : public View_Sprite {
public:
    friend class View_Wrapper;
    View_Character() {}
    View_Character(const std::string& sprite);
    virtual ~View_Character() = default;
    void spriteSetPosition(int x, int y);
    void setDirectorySprite(const std::string& sprite);
};