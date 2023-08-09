#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "View_Sprite.h"
class View_RoomPosition : public View_Sprite
{
private:
	sf::IntRect tilePart;
public:
	View_RoomPosition();
	void spriteSetPosition(int, int);
	void setDirectorySprite(std::string);
	void setTilePart(int, int);
	sf::Sprite& getSprite();
};