#include "Model_Player.h"

Model_Player::Model_Player(int health, float x, float y, int vel, int radio, int bulletVel)
    : Model_Character(health, x, y,vel, radio), health(health),velx(vel), vely(vel), bulletVel(bulletVel){
}
int Model_Player::getVelx(){
    return velx;
}
int Model_Player::getVely() {
    return vely;
}
void Model_Player::setVelx(int vel) {
    velx = vel;
}
void Model_Player::setVely(int vel) {
    vely = vel;
}
int Model_Player::getBulletVel() {
    return bulletVel;
}
void Model_Player::setBulletVel(int newBulletVel) {
    bulletVel = newBulletVel;
}
int Model_Player::getHealth() { 
    return health; 
}
void Model_Player::setHealth(int newHealth) { 
    health = newHealth; 
}