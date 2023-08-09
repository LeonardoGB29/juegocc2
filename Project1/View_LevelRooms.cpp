#include "View_LevelRooms.h"
#include <filesystem>
View_LevelRooms::View_LevelRooms() : View_Sprite()
{
	setDirectorySprite(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\Hud\\mapa.png");
	setTilePart(192, 192);
	spriteSetPosition(0,448);
}
void View_LevelRooms::spriteSetPosition(int x, int y) {
	View_Sprite::spriteSetPosition(x,y);//pal lugar ((x * 64) + x * 4) +4, (( y * 64 )+ y * 4)+452
}
void View_LevelRooms::setDirectorySprite(std::string sprite) {
	View_Sprite::setDirectorySprite(sprite);
}
void View_LevelRooms::setTilePart(int x, int y) {
	tilePart = sf::IntRect(0, 0, x, y);
	View_Sprite::setTilePart(tilePart);
}
sf::Sprite& View_LevelRooms::getSprite() {
	return View_Sprite::getSprite();
}