#pragma once
#include <SFML/Graphics.hpp>
#include "View_Wrapper.h"

class View_Sprite{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	friend class View_Wrapper;
	friend class View_Bullet;
	View_Sprite();
	virtual void setDirectorySprite(std::string);
	virtual void spriteSetPosition(int, int);// juntaremos estos dos en uno solo para view character
	virtual void setTilePart(int, int);
	void setTilePart(sf::IntRect part);
	sf::Sprite& getSprite();
	virtual void removeImage();
};