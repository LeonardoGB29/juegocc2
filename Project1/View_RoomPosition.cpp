#include "View_RoomPosition.h"
#include <filesystem>
View_RoomPosition::View_RoomPosition() : View_Sprite()
{
	setDirectorySprite(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\Hud\\you.png");
	setTilePart(48, 48);
	spriteSetPosition(0,0);
}
void View_RoomPosition::spriteSetPosition(int x, int y) {
	View_Sprite::spriteSetPosition((x * 64)+((2-x)*8), (y * 64) + 448+((2 - y) * 8));//pal lugar 
}
void View_RoomPosition::setDirectorySprite(std::string sprite) {
	View_Sprite::setDirectorySprite(sprite);
}
void View_RoomPosition::setTilePart(int x, int y) {
	tilePart = sf::IntRect(0, 0, x, y);
	View_Sprite::setTilePart(tilePart);
}
sf::Sprite& View_RoomPosition::getSprite() {
	return View_Sprite::getSprite();
}