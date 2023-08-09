#pragma once
#include "Model_TypeMap.h"
#include "Controller_RoomElement.h"
#include "Model_Room.h"
class Controller_Room
{
private:
	Model_Room RoomElements;
	Model_TypeMap map;
public:
	Controller_Room(Model_TypeMap&);
	void reloadMap(Model_TypeMap&);
	Model_Room& getRoomElements();
	void ElementsCollionwith(Controller_Player&);
	View_RoomElement& getViewRoomElement(int, int);
};
