#include "Model_RoomElement.h"
/*	std::string RE_path;
	int RE_position; //son de 11x y 7y
	int RE_type;
	Controller_Collision RE_Collision;*/

	//cambio en model 
Model_RoomElement::Model_RoomElement(int type, int position, Controller_Collision& collision, std::string path) {
	this->RE_path = path;
	this->RE_type = type;
	this->RE_position = position;
	this->RE_Collision = collision;
}
//se agregó constructor por defecto de controller collision;
Model_RoomElement::Model_RoomElement() {
	this->RE_path = std::filesystem::current_path().generic_string() + "\\resources\\sprites\\Backgound\\tileset1.png";
	this->RE_type = 0;
	this->RE_position = 0;
	this->RE_Collision = Controller_Collision(0, 0, 32, 0);
}
void Model_RoomElement::setRoomElementPath(std::string path) {
	this->RE_path = path;
}
Controller_Collision& Model_RoomElement::getRoomElementCollision() {
	return RE_Collision;
}
int Model_RoomElement::getType() {
	return RE_type;
}
void Model_RoomElement::setPosition(int x, int y) {
	RE_position = (y * 11) + x;
}
std::string Model_RoomElement::getPath() {
	return RE_path;
}

void Model_RoomElement::setTypeCollision(int type) {
	this->RE_type = type;
	RE_Collision.getModelCollision().setObjType(type);
}
void Model_RoomElement::Reload(char map) {
	if (map == '0') {
		setTypeCollision(0);
		RE_type = 0;
	}
	if (map == '1') {
		setTypeCollision(1);
		RE_type = 1;
	}
}