#pragma once
#include <iostream>
#include <filesystem>
#include <thread>
#include "Controller_Character.h"
#include "Model_Character.h"
#include "View_Player.h"
#include "Model_Player.h"
#include "Controller_Collision.h"
#include "Controller_Bullet.h"

class Controller_Bullet;

class Controller_Player : public Controller_Character {
private:
	View_Player& view;
	Model_Player& model; 
	Controller_Collision collisionP;
	UserInput& userInput;
	std::vector<Controller_Bullet*> bullets;
public:
	Controller_Player(Model_Player& model, View_Player& view, UserInput& userInput);
	void isCollisionWith(Controller_Collision&);
	void Update() override;
	int getCurrentDirection();
	Controller_Collision& getControllerCollision();
	Model_Player& getPlayerModel();
	void setControllerParameter(int);
	std::vector<Controller_Bullet*>& getBullets() {
		return bullets;
	}
};