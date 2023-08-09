#include "View_Character.h"

View_Character::View_Character(const std::string& sprite) {
    View_Sprite::setDirectorySprite(sprite);
    spriteSetPosition(0, 0);
}

void View_Character::spriteSetPosition(int x, int y) {
    View_Sprite::spriteSetPosition(x, y);
}

void View_Character::setDirectorySprite(const std::string& sprite) {
    View_Sprite::setDirectorySprite(sprite);
}

/*void View_Character::draw(sf::RenderWindow& window, float x, float y) {
    sprite.setPosition(x, y);
    window.draw(sprite);
}*/

