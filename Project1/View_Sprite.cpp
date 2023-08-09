#include "View_Sprite.h"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <string>

View_Sprite::View_Sprite() {
	texture.loadFromFile(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\collision\\collision.png");
	sprite.setTexture(texture);
}
void View_Sprite::spriteSetPosition(int x, int y) {
	sprite.setPosition(x, y);
}
void View_Sprite::setDirectorySprite(std::string spriteset) {
	texture.loadFromFile(spriteset);
	sprite.setTexture(texture);
}
void View_Sprite::setTilePart(int x, int y) {
	sf::IntRect part = sf::IntRect(0,0,x,y);
	sprite.setTextureRect(part);
}
void View_Sprite::setTilePart(sf::IntRect part) {
	sprite.setTextureRect(part);
}
sf::Sprite& View_Sprite::getSprite() {
	return sprite;
}
void View_Sprite::removeImage() {
	sf::Texture emptyTexture;
	sprite.setTexture(emptyTexture);
}