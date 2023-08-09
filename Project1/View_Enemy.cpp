#include "View_Enemy.h"

View_Enemy::View_Enemy(const std::string imageFilePath)
    : View_Character(imageFilePath) {}

void View_Enemy::spriteSetPosition(int x, int y) {
    View_Character::spriteSetPosition(x, y);
}

void View_Enemy::setDirectorySprite(std::string sprite) {
    View_Character::setDirectorySprite(sprite);
}