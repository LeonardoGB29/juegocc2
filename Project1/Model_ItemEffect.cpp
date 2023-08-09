#include "Model_ItemEffect.h"
#include "Model_Player.h"

void SpeedBoostEffect::applyEffect(Model_Player& player) {
    int currentSpeed = player.getVel();
    player.setVel(currentSpeed + 3);
}

void HealthBoostEffect::applyEffect(Model_Player& player) {
    int currentHealth = player.getHealth();
    player.setHealth(currentHealth + 25);
} 