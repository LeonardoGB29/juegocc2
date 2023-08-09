#include "Model_Character.h"
#include "View_Wrapper.h"
#include "View_Sprite.h"
#include "View_Collision.h"
#include "Controller_Collision.h"
#include "Controller_Player.h"
#include "Model_Collision.h"
#include "Controller_Game.h"
#include <filesystem>
#include <string>

int main() {
    Controller_Game game;
    std::cout << std::filesystem::current_path().string();
    game.runGame();
    return 0;
}