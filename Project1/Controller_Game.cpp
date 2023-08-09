#include <thread>
#include <iostream>
#include<filesystem>
#include "View_Wrapper.h"
#include "View_Player.h"
#include "View_Sprite.h"
#include "View_Game.h"
#include "View_Item.h"
#include "Model_Player.h"
#include "Model_Enemy.h"
#include "Model_Game.h"
#include "Controller_Update.h"
#include "Controller_Collision.h"
#include "Controller_Game.h"
#include "Controller_Player.h"
#include "Controller_Enemy.h"
#include "Controller_Bullet.h"
#include "Bullet.h"
#include "View_Room.h"
#include "Model_LevelRooms.h"
#include "Controller_LevelRooms.h"

Controller_Game::Controller_Game() :
    ventana(1088, 640, "JUEGO")
{}

void Controller_Game::runGame() {

    Model_Game gameModel;
    View_Game gameView;

    Controller_Player* controllerPlayer1 = new Controller_Player(gameModel.modelPlayer, gameView.viewPlayer1, ventana.userInput1);
    Controller_Player* controllerPlayer2 = new Controller_Player(gameModel.modelPlayer2, gameView.viewPlayer2, ventana.userInput2);
    player_Updater.addController(controllerPlayer1);
    player_Updater.addController(controllerPlayer2);

    Model_TypeMap map(std::filesystem::current_path().generic_string() + "\\resources\\maps\\level1\\normal\\1.txt");
    Controller_Room controllerRoom(map);

    std::vector<Controller_Player*> controllerPlayers;
    controllerPlayers.push_back(controllerPlayer1);
    controllerPlayers.push_back(controllerPlayer2);

    std::vector<Model_Player*> players;
    players.push_back(&gameModel.modelPlayer);
    players.push_back(&gameModel.modelPlayer2);

    //lista de colisiones de enemigos:
    collisionEnemies.push_back(Controller_Collision(0, 0, 16, 3));
    collisionEnemies.push_back(Controller_Collision(0, 0, 16, 3));

    //cambiao
    controllerEnemies.push_back(std::make_shared<Controller_Enemy>(gameModel.modelEnemy, gameView.viewEnemy, players, collisionEnemies[0])); // se le puede asignar de mejor manera
    controllerEnemies.push_back(std::make_shared<Controller_Enemy>(gameModel.modelEnemy2, gameView.viewEnemy2, players, collisionEnemies[1]));  //este tambien
    
    enemy_Updater.addController(controllerEnemies[0].get());
    enemy_Updater.addController(controllerEnemies[1].get());

    std::unique_ptr<ItemEffect> speedBoostEffect = std::make_unique<SpeedBoostEffect>();
    modelItems.push_back(Model_Item(800, 500, std::move(speedBoostEffect))); 
    Controller_Collision collisionItem1(800, 500, 32, 4); 
    controllerItems.push_back(Controller_Item(800, 500, std::move(modelItems[0].effect), players, gameView.viewItem1, collisionItem1));

    std::cout << controllerRoom.getRoomElements().getElement(10, 6).getModel().getRoomElementCollision().getModelCollision().getObjType();
    //zona de testeo;
    Controller_LevelRooms levelRooms(controllerEnemies,*controllerPlayers[0], *controllerPlayers[1], controllerRoom,gameView.viewLevelMap, gameView.viewRoomPosition);

    //final de la zona
    while (ventana.isOpen()) { 
        ventana.spriteDraw<View_Room>(gameView.viewRoom);
        Control_RoomElemets(controllerRoom);
        ventana.spriteDraw<View_Enemy>(gameView.viewEnemy);
        ventana.spriteDraw<View_Enemy>(gameView.viewEnemy2);
        ventana.spriteDraw<View_Player>(gameView.viewPlayer1);
        ventana.spriteDraw<View_Player>(gameView.viewPlayer2);
        ventana.spriteDraw<View_Item>(gameView.viewItem1);
        ventana.spriteDraw<View_LevelRooms>(gameView.viewLevelMap);
        ventana.spriteDraw<View_RoomPosition>(gameView.viewRoomPosition);


        levelRooms.Update(); //updatea las salas


        std::vector<Controller_Bullet*>& bulletsPlayer1 = controllerPlayers[0]->getBullets();
        for (Controller_Bullet* bullet : bulletsPlayer1) {
            for (auto collisionE1 : controllerEnemies) {
                collisionE1->isCollisionWith(*bullet);
            }
            ventana.spriteDraw<View_Bullet>(bullet->getView()); // Asume que hay un método getView() en Controller_Bullet
        }

        // Dibuja las balas para el jugador 2
        std::vector<Controller_Bullet*>& bulletsPlayer2 = controllerPlayers[1]->getBullets();
        for (Controller_Bullet* bullet : bulletsPlayer2) {
            for (auto collisionE1 : controllerEnemies) {
                collisionE1->isCollisionWith(*bullet);
            }
            ventana.spriteDraw<View_Bullet>(bullet->getView());
        }
        ventana.processEvents();
        controllerRoom.ElementsCollionwith(*controllerPlayers[0]);
        controllerRoom.ElementsCollionwith(*controllerPlayers[1]);
        //zona testeo

        //levelsRoom.DoorTrigger();

        //termina zona testeo

        std::thread threadPlayer1([&]() {controllerPlayers[0]->Update(); });
        std::thread threadPlayer2([&]() {controllerPlayers[1]->Update(); });
        threadPlayer1.join();
        threadPlayer2.join();

        enemy_Updater.update();

        for (auto& item : controllerItems){
            item.isCollisionWith(controllerPlayers[0]->getControllerCollision());
            item.isCollisionWith(controllerPlayers[1]->getControllerCollision());
        }
        
        //controllerPlayer1->isCollisionWith(test);
        Control_Collision_Enemy_Enemy();
        controllerEnemies[1]->isCollisionWith(controllerPlayers[1]->getControllerCollision());
        controllerEnemies[0]->isCollisionWith(controllerPlayers[1]->getControllerCollision());
        controllerEnemies[1]->isCollisionWith(controllerPlayers[0]->getControllerCollision());
        controllerEnemies[0]->isCollisionWith(controllerPlayers[0]->getControllerCollision());

        ventana.display();
        ventana.clear();
    };


}
void Controller_Game::Control_Collision_Enemy_Enemy() {
    for (auto collisionE1 : controllerEnemies) {
        for (Controller_Collision collisionE2 : collisionEnemies) {
            if (&collisionE1->getCollision() == &collisionE2) {} //verificamos si su direccion dememoria es lamisma para no juntarlos,solo si se compara 2 listas iguales (Enemies-Enemies)
            else {
                collisionE1->isCollisionWith(collisionE2);
            }
        }
    }
}
void Controller_Game::Control_RoomElemets(Controller_Room& controllerRoom) {
    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 11; i++) {
            if (!(controllerRoom.getRoomElements().getElement(i, j).getModel().getType() == 0))
                ventana.spriteDraw<View_RoomElement>(controllerRoom.getViewRoomElement(i, j));
        }

    }
}