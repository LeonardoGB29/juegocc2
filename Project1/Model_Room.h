#pragma once
#include "Model_RoomElement.h"
#include "Controller_RoomElement.h"
class Model_Room
{
private:
	int level;
	Controller_RoomElement roomElements[7][11];
public:
	Model_Room();
	Controller_RoomElement& getElement(int, int);
	void UpdateElement(int, int, std::string);
	void UpdateElement(int, int, int);
};

