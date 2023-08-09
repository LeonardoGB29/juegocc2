#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "View_Sprite.h"
class View_RoomElement : public View_Sprite
{
private:
	sf::IntRect tilePart;
public:
	View_RoomElement();
	void spriteSetPosition(float, float);
	void setDirectorySprite(std::string);
	void setTilePart(int, int);
	sf::Sprite& getSprite();
};

