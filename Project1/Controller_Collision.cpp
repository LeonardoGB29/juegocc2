#include "Controller_Collision.h"
#include "View_Collision.h"
#include "Model_Collision.h"
#include <filesystem>
#include <string>

Controller_Collision::Controller_Collision() {
	ModelC = Model_Collision(0,0,16,2);
}
Controller_Collision::Controller_Collision(int x, int y, int radius,int objType) {
	ModelC = Model_Collision(x, y, radius,objType);
}
Model_Collision& Controller_Collision::getModelCollision() {
	return ModelC;
}
void Controller_Collision::UpdatePosition(int x, int y) {
	ModelC.setPositionx(x);
	ModelC.setPositiony(y);
}
bool Controller_Collision::verificateCollision(Controller_Collision objC) {
	Model_Collision Objcheck = objC.getModelCollision();
	if (ModelC.checkCollision(Objcheck)) { //actualmente solo es un booleano pero estamos pensando en poner como int
		//tener todas las interacciones entre objetos con solo esta función
		return true;
	}
	return false;
}