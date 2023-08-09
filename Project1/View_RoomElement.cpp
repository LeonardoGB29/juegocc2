#include "View_RoomElement.h"
View_RoomElement::View_RoomElement() : View_Sprite()
{
	;
}
void View_RoomElement::spriteSetPosition(float x, float y) {
	View_Sprite::spriteSetPosition(x, y);
}
void View_RoomElement::setDirectorySprite(std::string sprite) {
	View_Sprite::setDirectorySprite(sprite);
}
void View_RoomElement::setTilePart(int x, int y) {
	tilePart = sf::IntRect(x * 64, y * 64, 64, 64);
	if ((x == 0) && (y == 0)) {
		tilePart = sf::IntRect(x, y, 0, 0);
	}
	View_Sprite::setTilePart(tilePart);
}
sf::Sprite& View_RoomElement::getSprite() {
	return View_Sprite::getSprite();
}