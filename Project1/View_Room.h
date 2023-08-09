#pragma once
#include "View_Sprite.h"
class View_Room : public View_Sprite
{
private:
	sf::IntRect tilePart;
public:
	View_Room();
	void spriteSetPosition(float, float);
	void setDirectorySprite(std::string);
	sf::Sprite& getSprite();
};


