#include "View_Item.h"
#include "View_Sprite.h"

View_Item::View_Item(const std::string& sprite) {
    View_Sprite::setDirectorySprite(sprite);
    spriteSetPosition(0, 0);
}

void View_Item::spriteSetPosition(int x, int y) {
    View_Sprite::spriteSetPosition(x, y);
}

void View_Item::setDirectorySprite(const std::string& sprite) {
    View_Sprite::setDirectorySprite(sprite);
}

void View_Item::removeImage() {
    View_Sprite::removeImage();
}