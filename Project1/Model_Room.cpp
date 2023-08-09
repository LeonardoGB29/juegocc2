#include "Model_Room.h"
Model_Room::Model_Room() {
}
Controller_RoomElement& Model_Room::getElement(int x, int y) {
	return roomElements[y][x];
}
void Model_Room::UpdateElement(int y, int x, std::string path) {
	roomElements[y][x].reload_path(path);
}
void Model_Room::UpdateElement(int y, int x, int z) {
	roomElements[y][x].getModel().setTypeCollision(z);
}