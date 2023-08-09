#include "View_Game.h"
#include <iostream>
#include<filesystem>

View_Game::View_Game() :
    viewPlayer1(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\collision\\1.png"),
    viewPlayer2(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\collision\\2.png"),
    viewEnemy(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\collision\\polpo.png"),
    viewEnemy2(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\collision\\polpo2.png"),
    viewBullet(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\collision\\bullet.png"),
    bulletSprite(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\collision\\bullet.png"),
    viewItem1(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\collision\\potion.png")
{
    viewRoom.setDirectorySprite(std::filesystem::current_path().generic_string() + "\\resources\\sprites\\Backgound\\bg1.png");
    viewPlayer2.setTilePart(54, 68);
}