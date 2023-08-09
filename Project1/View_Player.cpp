#include "View_Player.h"

View_Player::View_Player(const std::string imageFilePath)
    : View_Character(imageFilePath) {}

void View_Player::spriteSetPosition(int x, int y) {
    View_Character::spriteSetPosition(x, y);
}
void View_Player::setDirectorySprite(std::string sprite) {
    View_Character::setDirectorySprite(sprite);
}