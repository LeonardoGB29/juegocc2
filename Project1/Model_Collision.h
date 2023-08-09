#pragma once
#include <iostream>
class Model_Collision{
private:
	int radius;
	int positionx;
	int positiony;
	int objType;
	std::string sprite;
public:
	Model_Collision();
	Model_Collision(int, int, int,int);
	int getPositionx();
	int getPositiony();
	int getRadius();
	int getObjType();
	//std::string getString();
	void setPositionx(int);
	void setPositiony(int);
	void setRadius(int);
	void setObjType(int);
	bool checkCollision(Model_Collision &);
};

