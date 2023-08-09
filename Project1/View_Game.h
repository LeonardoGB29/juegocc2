#pragma once
#include <iostream>
#include<filesystem>

#include "View_Wrapper.h"
#include "Controller_Update.h"
#include "Controller_Collision.h"
#include "Controller_Game.h"
#include "Model_Player.h"
#include "Model_Enemy.h"
#include "View_Player.h"
#include "View_Sprite.h"
#include "View_Bullet.h"
#include "View_Item.h"
#include "Controller_Player.h"
#include "Controller_Enemy.h"
#include "Controller_Bullet.h"
#include "Bullet.h"
#include "View_Room.h"
#include "View_LevelRooms.h"
#include "View_RoomPosition.h"

class View_Game {
public:
    View_Player viewPlayer1;
    View_Player viewPlayer2;
    View_Sprite bg;
    View_Enemy viewEnemy;
    View_Enemy viewEnemy2;
    View_Bullet viewBullet;
    View_Item viewItem1;
    View_Room viewRoom;
    View_LevelRooms viewLevelMap;
    std::string bulletSprite;
    View_RoomPosition viewRoomPosition;

    View_Game();

};

