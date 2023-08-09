#pragma once
#include "Controller_Room.h"
#include "Controller_Enemy.h"
#include "Controller_Enemy.h"
#include "Model_TypeMap.h"
class Model_LevelMap
{
private:
	int enemys;
	int actualLevelRoom;
	int mode;
	Model_TypeMap *maps[10];
	Controller_Room& room;
public:
	Model_LevelMap(Controller_Room&);
	void putEnemies(std::vector<std::shared_ptr<Controller_Enemy>>, int);
	void Update();
	~Model_LevelMap();
};

