#include "View_Bullet.h"
#include "View_Sprite.h"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <string>

View_Bullet::View_Bullet(const std::string& sprite) {
    View_Sprite::setDirectorySprite(sprite);
    spriteSetPosition(0, 0);
}

void View_Bullet::spriteSetPosition(int x, int y) {
    View_Sprite::spriteSetPosition(x, y);
}

void View_Bullet::setDirectorySprite(const std::string& sprite) {
    View_Sprite::setDirectorySprite(sprite);
}
