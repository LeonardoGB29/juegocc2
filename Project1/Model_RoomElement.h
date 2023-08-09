#pragma once
#include <iostream>
#include <filesystem>
#include "Controller_Collision.h"
class Model_RoomElement
{
private:
	std::string RE_path;
	int RE_position; //son de 11x y 7y
	int RE_type;
	Controller_Collision RE_Collision;
public:
	Model_RoomElement(int, int, Controller_Collision&, std::string);
	Model_RoomElement();
	void setRoomElementPath(std::string);
	Controller_Collision& getRoomElementCollision();
	int getType();
	void setPosition(int x, int y);
	void setTypeCollision(int);
	std::string getPath();
	void Reload(char map);
};


