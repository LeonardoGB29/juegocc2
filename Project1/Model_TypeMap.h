#pragma once
#include <iostream>
#include <fstream>
class Model_TypeMap
{
private:
	char map[7][11];
	int typemap;
public:
	Model_TypeMap(std::string);
	void setFilePath(std::string);
	void setTypeRoom(int type);
	int getTypeRoom();
	char getElementMap(int, int);
	void checkMap();
};
