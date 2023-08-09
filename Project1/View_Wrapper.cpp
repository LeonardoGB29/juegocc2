#include <iostream>
#include "View_Wrapper.h"
#include "View_Sprite.h"

View_Wrapper::View_Wrapper(int width, int height, const std::string& title) {
    window.create(sf::VideoMode(width, height), title);
    window.setFramerateLimit(60);
}

bool View_Wrapper::isOpen() {
    return window.isOpen();
}

void View_Wrapper::close() {
    window.close();
}

void View_Wrapper::clear() {
    window.clear();
}

void View_Wrapper::display() {
    window.display();
}

void View_Wrapper::draw(const sf::Drawable& drawable) {
    window.draw(drawable);
}

void View_Wrapper::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {

        // Player 1 input
        userInput1.moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        userInput1.moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        userInput1.moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        userInput1.moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !userInput1.shootProcessed) {
            userInput1.shoot = true;
            userInput1.shootProcessed = true;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
            userInput1.shootProcessed = false;
            userInput1.shoot = false;
        }

        // Player 1 shoot
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W && !userInput1.shootUpProcessed) {
            userInput1.shootUp = true;
            userInput1.shootUpProcessed = true;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W) {
            userInput1.shootUpProcessed = false;
            userInput1.shootUp = false;
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S && !userInput1.shootDownProcessed) {
            userInput1.shootDown = true;
            userInput1.shootDownProcessed = true;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S) {
            userInput1.shootDownProcessed = false;
            userInput1.shootDown = false;
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A && !userInput1.shootLeftProcessed) {
            userInput1.shootLeft = true;
            userInput1.shootLeftProcessed = true;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A) {
            userInput1.shootLeftProcessed = false;
            userInput1.shootLeft = false;
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D && !userInput1.shootRightProcessed) {
            userInput1.shootRight = true;
            userInput1.shootRightProcessed = true;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D) {
            userInput1.shootRightProcessed = false;
            userInput1.shootRight = false;
        }

        // ----------------------------------------------------------------------------------------------------------------------------------
        // Player 2 input 
        userInput2.moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        userInput2.moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        userInput2.moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        userInput2.moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        
        // Player 2 shoot 
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L && !userInput2.shootProcessed) {
            userInput2.shoot = true;
            userInput2.shootProcessed = true;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::L) {
            userInput2.shootProcessed = false;
            userInput2.shoot = false;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up && !userInput2.shootUpProcessed) {
            userInput2.shootUp = true;
            userInput2.shootUpProcessed = true;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
            userInput2.shootUpProcessed = false;
            userInput2.shootUp = false;
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down && !userInput2.shootDownProcessed) {
            userInput2.shootDown = true;
            userInput2.shootDownProcessed = true;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down) {
            userInput2.shootDownProcessed = false;
            userInput2.shootDown = false;
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left && !userInput2.shootLeftProcessed) {
            userInput2.shootLeft = true;
            userInput2.shootLeftProcessed = true;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left) {
            userInput2.shootLeftProcessed = false;
            userInput2.shootLeft = false;
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right && !userInput2.shootRightProcessed) {
            userInput2.shootRight = true;
            userInput2.shootRightProcessed = true;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right) {
            userInput2.shootRightProcessed = false;
            userInput2.shootRight = false;
        }
        
        if (event.type == sf::Event::Closed)
            window.close();
    }
}
