#pragma once
#include <vector>
#include "Controller_Character.h"
template <typename T>
class Controller_Update {
private:
    std::vector<T*> controllers;
public:
    void addController(T* controller);
    void update();
};

template <typename T>
void Controller_Update<T>::addController(T* controller) {
    controllers.push_back(controller);
}

template <typename T>
void Controller_Update<T>::update() {
    for (auto controller : controllers) {
        controller->Update();
    }
}