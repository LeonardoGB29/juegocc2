#include "Model_Enemy.h"
#include "Model_Character.h"

Model_Enemy::Model_Enemy(int health, float x, float y,int vel, int radio)
    : Model_Character(health, x, y, vel, radio), vel(vel) {
    healthinicial = health;
}

int Model_Enemy::getVel() {
    return vel;
}

void Model_Enemy::setVel(int newVel) {
    vel = newVel;
}
void Model_Enemy::setHealthInicial() {
    setHealth(healthinicial);
}