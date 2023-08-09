#pragma once
#include <SFML/Graphics.hpp>
#include "Model_Character.h"
#include "View_Sprite.h"


struct UserInput {
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool shoot = false;
    bool shootProcessed = false;
    bool shootUp = false;
    bool shootDown = false;
    bool shootLeft = false;
    bool shootRight = false;
    bool shootUpProcessed = false;
    bool shootDownProcessed = false;
    bool shootLeftProcessed = false;
    bool shootRightProcessed = false;
};

struct UserInput1 : UserInput {
};

struct UserInput2 : UserInput {
};

class View_Wrapper {
public:
    sf::RenderWindow window;
    UserInput userInput1;
    UserInput userInput2;
    View_Wrapper(int width, int height, const std::string& title);
    bool isOpen();
    void close();
    void clear();
    void display();
    void draw(const sf::Drawable& drawable);
    void processEvents();
    template <typename T>
    void spriteDraw(T sprite);
};

template <typename T>
void View_Wrapper::spriteDraw(T sprite) {
    window.draw(sprite.sprite);
}

