#pragma once
#include "Model_Collision.h"
#include <iostream>

class Controller_Collision {
private:
	Model_Collision ModelC;
public:
	Controller_Collision();
	Controller_Collision(int, int, int,int);
	Model_Collision& getModelCollision();
	void UpdatePosition(int,int);
	bool verificateCollision(Controller_Collision);
	/*void setPositionCollition(Model_Collision&, View_Collision&);
	void messageStateVisualCollition(Model_Collision&, View_Collision&);
	void objectCollition(Model_Collision&, Model_Collision&, View_Collision&, View_Collision&);
	void update();*/
};