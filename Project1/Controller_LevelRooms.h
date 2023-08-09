#pragma once
#include "Model_LevelRooms.h"
#include "View_LevelRooms.h"
#include "View_RoomPosition.h"
#include "Controller_Enemy.h"
#include <vector>
class Controller_LevelRooms
{
private:
	Model_LevelRooms* model;
	View_LevelRooms& view;
	View_RoomPosition& viewPosition;
	std::vector<std::shared_ptr<Controller_Enemy>>& enemiesController;
	//view_LevelsPosition
	//View_Doors?
	Controller_Player& player1;
	Controller_Player& player2;
	Controller_Room& room;
	int numEnemiesDied ;
public:
	Controller_LevelRooms(std::vector<std::shared_ptr<Controller_Enemy>>& enemiesController,Controller_Player&, Controller_Player&, Controller_Room& room, View_LevelRooms& view, View_RoomPosition& viewPosition);
	void Update();
	~Controller_LevelRooms();
};

