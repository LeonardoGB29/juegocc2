#include "Controller_LevelRooms.h"
Controller_LevelRooms::Controller_LevelRooms(std::vector<std::shared_ptr<Controller_Enemy>>& enemiesController,Controller_Player& player1, Controller_Player& player2, Controller_Room& room, View_LevelRooms& view
	,View_RoomPosition& viewPosition):
	enemiesController(enemiesController), player1(player1), player2(player2), room(room),view(view),viewPosition(viewPosition){
	model = new Model_LevelRooms(player1, player2, room, enemiesController);
	numEnemiesDied = 0;

}
void Controller_LevelRooms::Update() {
	if (model->DoorTrigger()) {
		viewPosition.spriteSetPosition(model->getPlayerPositionX(), model->getPlayerPositionY());
	}
	numEnemiesDied = 0;
	for (auto enemy : enemiesController) {
		if (enemy->getModel().getHealth() <= 0) {
			numEnemiesDied++;
		}
	}
	if (numEnemiesDied == enemiesController.size()) {
		model->getElementMinimap(model->getPlayerPositionX(), model->getPlayerPositionY()) = '0';
	}
}
Controller_LevelRooms::~Controller_LevelRooms(){
	delete model;
}