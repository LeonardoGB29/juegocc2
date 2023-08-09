#include "Controller_Room.h"
Controller_Room::Controller_Room(Model_TypeMap& map) : map(map) {
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 11; i++) {
			std::cout << "*" << map.getElementMap(j, i) << "*";
			RoomElements.getElement(i, j).Reload(map.getElementMap(j, i));
			RoomElements.getElement(i, j).setPosition(i, j);
		}
		std::cout << std::endl;
	}
}
void Controller_Room::reloadMap(Model_TypeMap& map) {
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 11; i++) {
			RoomElements.getElement(i, j).Reload(map.getElementMap(j, i));
		}
	}
	this->map = map;
}
Model_Room& Controller_Room::getRoomElements() {
	return RoomElements;
}
void Controller_Room::ElementsCollionwith(Controller_Player& player) {
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 11; i++) {
			if (map.getElementMap(j, i) == '1') {
				//controllerRoom.getRoomElements().getElement(10, 6).getModel().getRoomElementCollision()
				player.isCollisionWith(RoomElements.getElement(i, j).getModel().getRoomElementCollision());
			}
		}

	}
}
//ventana.spriteDraw<View_RoomElement>(controllerRoom.getRoomElements().getElement(10, 6).getView());
View_RoomElement& Controller_Room::getViewRoomElement(int x, int y) {
	return RoomElements.getElement(x, y).getView();
}
