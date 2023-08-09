#include "Model_LevelRooms.h"
#include <iostream>
Model_LevelRooms::Model_LevelRooms(Controller_Player& plyr1, Controller_Player& plyr2, Controller_Room& room, std::vector<std::shared_ptr<Controller_Enemy>>& enemiesController) :
	enemiesController(enemiesController),
	controllerPlayer1(plyr1),
	controllerPlayer2(plyr2), room(room)
{
	maps[0] = new Model_TypeMap(std::filesystem::current_path().generic_string() + "\\resources\\maps\\level1\\normal\\0.txt");
	maps[1] = new Model_TypeMap(std::filesystem::current_path().generic_string() + "\\resources\\maps\\level1\\normal\\1.txt");
	maps[2] = new Model_TypeMap(std::filesystem::current_path().generic_string() + "\\resources\\maps\\level1\\normal\\2.txt");
	maps[3] = new Model_TypeMap(std::filesystem::current_path().generic_string() + "\\resources\\maps\\level1\\normal\\3.txt");
	maps[4] = new Model_TypeMap(std::filesystem::current_path().generic_string() + "\\resources\\maps\\level1\\normal\\4.txt");
	maps[5] = new Model_TypeMap(std::filesystem::current_path().generic_string() + "\\resources\\maps\\level1\\normal\\5.txt");
	maps[6] = new Model_TypeMap(std::filesystem::current_path().generic_string() + "\\resources\\maps\\level1\\normal\\6.txt");
	maps[7] = new Model_TypeMap(std::filesystem::current_path().generic_string() + "\\resources\\maps\\level1\\normal\\7.txt");
	maps[8] = new Model_TypeMap(std::filesystem::current_path().generic_string() + "\\resources\\maps\\level1\\normal\\8.txt");
	actualstage = 0;
	playerPositionX = 0; //posicion del player
	playerPositionY = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			minimap[i][j] = '1';
		}
	}
	minimap[0][0] = '0';
	//matamos a todos los enemigos:
	for (auto enemy : enemiesController) {
		enemy->getModel().setHealth(-1);
	}
}
int& Model_LevelRooms::getPlayerPositionX() {
	return playerPositionX;
}
int& Model_LevelRooms::getPlayerPositionY() {
	return playerPositionY;
}
int& Model_LevelRooms::getActualStage() {
	return actualstage;
}
char& Model_LevelRooms::getElementMinimap(int x, int y) {
	return minimap[x][y];
}
bool Model_LevelRooms::DoorTrigger() {
	//door left:
	if (getElementMinimap(playerPositionX, playerPositionY) == '0') {
		if (playerPositionX != 2) {
			if (controllerPlayer1.getControllerCollision().getModelCollision().getPositionx() + 30 > 896) {
				playerPositionX++;
				controllerPlayer1.getPlayerModel().setPosition(224, 320);
				controllerPlayer2.getPlayerModel().setPosition(224, 320);
				std::cout << 1;
				Reload();
				if (getElementMinimap(playerPositionX, playerPositionY) == '1') {
					for (auto enemy : enemiesController) {
						enemy->getModel().setHealthInicial();
						enemy->getModel().setPosition(832, 320);
					}
				}
				return true;
			}
		}
		//door rigth:

		if (playerPositionX != 0) {
			if (controllerPlayer1.getControllerCollision().getModelCollision().getPositionx() < 192) {
				playerPositionX--;
				controllerPlayer1.getPlayerModel().setPosition(800, 320);
				controllerPlayer2.getPlayerModel().setPosition(800, 320);
				std::cout << 2;
				Reload();
				if (getElementMinimap(playerPositionX, playerPositionY) == '1') {
					for (auto enemy : enemiesController) {
						enemy->getModel().setHealthInicial();
						enemy->getModel().setPosition(192, 320);
					}
				}
				return true;

			}
		}
		//door up:
		if (playerPositionY != 0) {
			if (controllerPlayer1.getControllerCollision().getModelCollision().getPositiony() < 128) {
				playerPositionY--;
				controllerPlayer1.getPlayerModel().setPosition(512, 480);
				controllerPlayer2.getPlayerModel().setPosition(512, 480);
				std::cout << 3;
				Reload();
				if (getElementMinimap(playerPositionX, playerPositionY) == '1') {
					for (auto enemy : enemiesController) {
						enemy->getModel().setHealthInicial();
						enemy->getModel().setPosition(192, 320);
					}
				}
				return true;
			}
		}
		//door down:
		if (playerPositionY != 2) {
			if (controllerPlayer1.getControllerCollision().getModelCollision().getPositiony() + 30 > 640) {
				playerPositionY++;
				controllerPlayer1.getPlayerModel().setPosition(512, 160);
				controllerPlayer2.getPlayerModel().setPosition(512, 160);
				std::cout << 4;
				Reload();
				if (true) {
					for (auto enemy : enemiesController) {
						enemy->getModel().setHealthInicial();
						enemy->getModel().setPosition(832, 320);
					}
				}
				return true;
			}
		}
	}
	return false;
}
void Model_LevelRooms::Reload() {
	int position = playerPositionX+(3* playerPositionY);
	std::cout << position;
	room.reloadMap(*maps[position]);
}
Model_LevelRooms::~Model_LevelRooms() {
	for (int i = 0; i < 9; i++) {
		delete maps[i];
	}
}