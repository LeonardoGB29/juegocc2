#include "Model_Collision.h"
#include <cmath>
Model_Collision::Model_Collision() {}

Model_Collision::Model_Collision (int x, int y, int radius, int objType) {
	this->positionx = x;
	this->positiony = y;
	this->objType = objType;
	this->radius = radius;
}
int Model_Collision::getPositionx() {
	return positionx;
};
int Model_Collision::getPositiony() {
	return positiony;
}
int Model_Collision::getRadius() {
	return radius;
}
int Model_Collision::getObjType() {
	return objType;
}
void Model_Collision::setPositionx(int x) {
	positionx = x;
};
void Model_Collision::setPositiony(int y) {
	positiony = y;
};
void Model_Collision::setRadius(int radius) {
	this->radius = radius;
};
void Model_Collision::setObjType(int objType) {
	this->objType = objType;
}
bool Model_Collision::checkCollision(Model_Collision& Collision2) {
	int d = sqrt(pow(Collision2.getPositionx() - positionx, 2) + pow(Collision2.getPositiony() - positiony, 2));
	if(d > radius+Collision2.getRadius()){
		return false;
	}
	return true;
}
