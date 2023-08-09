#include "View_Room.h"
#include "View_RoomElement.h"
View_Room::View_Room() : View_Sprite()
{
	spriteSetPosition(128, 64);
}
void View_Room::spriteSetPosition(float x, float y) {
	View_Sprite::spriteSetPosition(x, y);
}
void View_Room::setDirectorySprite(std::string sprite) {
	tilePart = sf::IntRect(0,0, 832, 576);
	View_Sprite::setTilePart(tilePart);
	View_Sprite::setDirectorySprite(sprite);
}
sf::Sprite& View_Room::getSprite() {
	return View_Sprite::getSprite();
}