#include "Model_TypeMap.h"
Model_TypeMap::Model_TypeMap(std::string path) {
	setFilePath(path);
	typemap = 0;
}
void Model_TypeMap::setFilePath(std::string path) {
	std::ifstream roomText(path);
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 11; i++) {
			roomText >> map[j][i];
		}
	}
}
char Model_TypeMap::getElementMap(int x, int y) {
	return map[x][y];
}
void Model_TypeMap::setTypeRoom(int type) {
	this->typemap = type;
}
int Model_TypeMap::getTypeRoom() {
	return typemap;
}
void Model_TypeMap::checkMap() {
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < 11; i++) {
			std::cout << map[j][i] << " ";
		}
		std::cout << std::endl;
	}
}