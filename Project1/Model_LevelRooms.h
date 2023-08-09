#pragma once+
#include "Model_TypeMap.h"
#include "Controller_Enemy.h"
#include <vector>
#include "Controller_Room.h"
class Model_LevelRooms
{
private:
	Model_TypeMap *maps[9];
	char minimap[3][3];

	int actualstage;
	int playerPositionX=0; //posicion del player
	int playerPositionY=0; //posicion del player
	std::vector<std::shared_ptr<Controller_Enemy>>& enemiesController;
	//std::vector<Controller_Player>& controllerPlayers;
	Controller_Player& controllerPlayer1;
	Controller_Player& controllerPlayer2;
	Controller_Room& room;
public:
	Model_LevelRooms(Controller_Player& plyr1, Controller_Player& plyr2, Controller_Room& room, std::vector<std::shared_ptr<Controller_Enemy>>& enemiesController);
	int& getPlayerPositionX();
	int& getActualStage();
	char& getElementMinimap(int, int);
	int& getPlayerPositionY();
	bool DoorTrigger();
	void Reload();
	~Model_LevelRooms();
};

