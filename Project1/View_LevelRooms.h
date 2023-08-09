#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "View_Sprite.h"
class View_LevelRooms : public View_Sprite
{
private:
	sf::IntRect tilePart;
public:
	View_LevelRooms();
	void spriteSetPosition(int, int);
	void setDirectorySprite(std::string);
	void setTilePart(int, int);
	sf::Sprite& getSprite();
};
