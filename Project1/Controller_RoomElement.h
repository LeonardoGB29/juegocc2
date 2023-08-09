#pragma once
#include "Model_RoomElement.h"
#include "View_RoomElement.h"
#include "Controller_Player.h"
#include "Controller_Collision.h"
#include <memory>
class Controller_RoomElement
{
private:
	View_RoomElement RE_view;
	Model_RoomElement RE_model;
public:
	Controller_RoomElement(View_RoomElement&, Model_RoomElement&);
	Controller_RoomElement();
	Model_RoomElement& getModel();
	View_RoomElement& getView();
	void reload_path(std::string);
	void Reload(char);
	void setPosition(int x, int y);
	void update();
};


