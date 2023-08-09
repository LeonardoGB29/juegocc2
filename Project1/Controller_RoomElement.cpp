#include "Controller_RoomElement.h"
/*	View_RoomElement& RE_view;
	Model_RoomElement& RE_model;
	Controller_Collision& RE_collision;*/
Controller_RoomElement::Controller_RoomElement(View_RoomElement& view, Model_RoomElement& model)
{
	RE_model = model;
	RE_view = view;
}
Controller_RoomElement::Controller_RoomElement() {
	RE_view.setDirectorySprite(RE_model.getPath());
}
Model_RoomElement& Controller_RoomElement::getModel() {
	return RE_model;
}
View_RoomElement& Controller_RoomElement::getView() {
	return RE_view;
}
void Controller_RoomElement::reload_path(std::string path) {
	RE_view.setDirectorySprite(path);
}
void Controller_RoomElement::setPosition(int x, int y) {
	RE_model.setPosition(x, y);
	RE_view.spriteSetPosition((x * 64) + 192, (y * 64) + 128);
	RE_model.getRoomElementCollision().UpdatePosition((x * 64) + 192, (y * 64) + 128);
}
void Controller_RoomElement::Reload(char map) {
	RE_model.Reload(map);
	if (map == '0') {
		RE_view.setTilePart(0, 0);
	}
	if (map == '1') {
		RE_view.setTilePart(0, 1);
	}
}
void Controller_RoomElement::update() {
}