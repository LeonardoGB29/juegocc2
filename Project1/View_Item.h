#pragma once
#include "View_Sprite.h"

class View_Item : public View_Sprite {
public:
    friend class View_Wrapper;
    View_Item() {}
    View_Item(const std::string& sprite);
    virtual ~View_Item() = default;
    void spriteSetPosition(int x, int y);
    void setDirectorySprite(const std::string& sprite);
    void removeImage();
};