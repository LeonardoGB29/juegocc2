#include "Model_Character.h"

Model_Character::Model_Character(int health, float x, float y,int vel,int radio) {//(health, x, y)
	this->health = health;
	this->vel = vel;
	position[0] = x;
	position[1] = y;
	this->radio = radio;
}
void Model_Character::setHealth(int health) {
	if (health + this->health == 100)
		this->health = 100;
	else
		this->health = health;
}
int Model_Character::getHealth() {
	return health;
}
float Model_Character::getPositionX() {
	return position[0];
}
float Model_Character::getPositionY() {
	return position[1];
}
int Model_Character::getVel() {
	return vel;
}
void Model_Character::setVel(int vel) {
	this->vel = vel;
}
void Model_Character::setPosition(int x, int y) {
	position[0] = x; //this->x = x;
	position[1] = y; //this->y = y;
}
int Model_Character::getRadius() {
	return radio;
}
void Model_Character::setRadius(int x) {
	radio = x;
}